#include<iostream>
#include<cmath>
#include "Role.h"
#include "KeQing.h"

//副属性问题
void SolveSub()
{
	cout << "风鹰剑刻晴攻/雷/暴副属性攻略" << endl;
	cout << "攻击力百分比  攻击力  暴击率 暴击伤害" << endl;
	
	for (int i = 25; i <= 45; i++)
	{
		KeQing kq;
		kq.WP(2);
		kq.R(0);
		kq.RM(0);
		kq.Resolve(i);
		cout << "  " << kq.nabp << "           " << kq.naba << "        " << kq.ncr << "        " << kq.ncd << endl;
	}
	
}

//主属性问题
void SolveMain()
{
	for (int i = 20; i <= 40; i++)
	{
		KeQing kq1;
		kq1.WP(2);
		kq1.R(0);
		kq1.RM(0);
		kq1.Resolve(i);

		KeQing kq2;
		kq2.WP(2);
		kq2.R(0);
		kq2.RM(1);
		kq2.Resolve(i);

		KeQing kq = kq1.ExpD() > kq2.ExpD() ? kq1 : kq2;
		cout << kq1.ExpD() << "  " << kq2.ExpD() << "  " << kq.Atk * (1 + kq.AtkBonusPer / 100) + kq.AtkBonusAdd << "           " << kq.CriRate << "        " << kq.CriDamage << endl;
	}
}

void main()
{
	SolveMain();
}