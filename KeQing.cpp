#include "KeQing.h"

KeQing::KeQing()
{
	Atk = 323;
	CriRate += 15;//´óÕÐ
	CriDamage += 38.4;//Í»ÆÆ
	
	wp = 0;
	r = 0;
	rm = 0;
}

void KeQing::WP(int i)
{
	switch (i)
	{
	case 0://Ï»ÀïÁúÒ÷

		break;
	case 1://Ìì¿Õ

		break;
	case 2://·çÓ¥½£
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
	case 0://ÈçÀ×2+½Ç¶·2
		Inc += 15;
		AtkBonusPer += 18;
		break;
	case 1://Æ½À×
		Inc += 35;
		break;
	default:
		break;
	}
	r = i;
}

void KeQing::RM(int i)
{
	AtkBonusAdd += 311;//Óð
	AtkBonusPer += 46.6;//É³
	switch (i)
	{
	case 0://À×/±©
		Inc += 46.6;
		CriRate += 31.1;
		Maxncr = 24;
		break;
	case 1://À×/±©ÉË
		Inc += 46.6;
		CriDamage += 62.2;
		Maxncd = 24;
		break;
	case 2://¹¥/±©
		AtkBonusPer += 46.6;
		CriRate += 31.1;
		Maxncr = 24;
	case 3://¹¥/±¬ÉË
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