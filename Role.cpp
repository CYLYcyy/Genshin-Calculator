#include"Role.h"

//伤害期望
double Role::ExpD() const
{
	if (CriRate < 100)
		return (Atk * (1 + AtkBonusPer / 100) + AtkBonusAdd) * (1 + per / 100 * Inc / 100) * (1 + CriRate / 100 * CriDamage / 100);
	else
		return (Atk * (1 + AtkBonusPer / 100) + AtkBonusAdd) * (1 + per / 100 * Inc / 100) * (1 + CriDamage / 100);
}

//直接替换为更优;
void Role::compare(const Role& compare)
{
	if (compare.ExpD() > ExpD())
	{
		*this = compare;
	}
}


Role Role::Iabp(int n)
{
	Role temp(*this);
	for (int i = 0; i < n; i++)
	{
		temp.AtkBonusPer += 4.975;
		temp.nabp++;
	}
	return temp;
}

Role Role::Iaba(int n)
{
	Role temp(*this);
	for (int i = 0; i < n; i++)
	{
		temp.AtkBonusAdd += 17;
		temp.naba++;
	}
	return temp;
}

Role Role::Icr(int n)
{
	Role temp(*this);
	for (int i = 0; i < n; i++)
	{
		temp.CriRate += 3.3;
		temp.ncr++;
	}
	return temp;
}

Role Role::Icd(int n)
{
	Role temp(*this);
	for (int i = 0; i < n; i++)
	{
		temp.CriDamage += 6.6;
		temp.ncd++;
	}
	return temp;
}

//最佳属性求解,n为有效副属性点数
void Role::Resolve(int n)
{
	int nn = n < 45 ? n : 45;
	Role temp(*this);
	for (int i = 0; i <= nn &&i<=Maxnabp; i++)
		for (int j = 0; j <= nn - i && i <= Maxnaba; j++)
			for (int k = 0; k <= nn - i - j && i <= Maxncr; k++)
			{
				if (nn - i - j - k <= Maxncd)
					compare(temp.Iabp(i).Iaba(j).Icr(k).Icd(nn - i - j - k));
			}
				
}