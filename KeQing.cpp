#include "KeQing.h"

KeQing::KeQing()
{
	Atk = 323;
	CriRate += 15;//����
	CriDamage += 38.4;//ͻ��
	
	wp = 0;
	r = 0;
	rm = 0;
}

void KeQing::WP(int i)
{
	switch (i)
	{
	case 0://ϻ������

		break;
	case 1://���

		break;
	case 2://��ӥ��
		Atk += 674;
		AtkBonusPer += 20;
		break;
	default:
		break;
	}
	wp = i;
}

void KeQing::R(int i)
{
	switch (i)
	{
	case 0://����2+�Ƕ�2
		Inc += 15;
		AtkBonusPer += 18;
		break;
	case 1://ƽ��
		Inc += 35;
		break;
	default:
		break;
	}
	r = i;
}

void KeQing::RM(int i)
{
	AtkBonusAdd += 311;//��
	AtkBonusPer += 46.6;//ɳ
	switch (i)
	{
	case 0://��/��
		Inc += 46.6;
		CriRate += 31.1;
		Maxncr = 24;
		break;
	case 1://��/����
		Inc += 46.6;
		CriDamage += 62.2;
		Maxncd = 24;
		break;
	case 2://��/��
		AtkBonusPer += 46.6;
		CriRate += 31.1;
		Maxncr = 24;
	case 3://��/����
		AtkBonusPer += 46.6;
		CriDamage += 62.2;
		Maxncd = 24;
	default:
		break;
	}
	rm = i;
}

void KeQing::Resolve(int n)
{
	Role::Resolve(n);
}