#include "KeLi.h"

KeLi::~KeLi()
{

}

double KeLi::AE() const
{
	if (r == 1)
		return 0.15;
	else
		return 0;
}

KeLi::KeLi()
{
	mBaseAttack = 311;
	mDamageIncrease += 28.8;//突破火伤
}

void KeLi::WP(int i)
{
	switch (i)
	{
    case 4://四风原典
		mBaseAttack += 608;
		mCriticalRate += 33.1;
		mDamageIncrease += 32;
		break;
    case 5://天空之卷
		mBaseAttack += 674;
		mAttackPercent += 33.1;
		mDamageIncrease += 12;
		break;
    case 1://流浪乐章1
		mBaseAttack += 510;
		mCriticalDamage += 55.1;
		mAttackPercent += 60;
		break;
    case 2://流浪乐章2
		mBaseAttack += 510;
		mCriticalDamage += 55.1;
		mDamageIncrease += 48;
		break;
    case 3://流浪乐章3
		mBaseAttack += 510;
		mCriticalDamage += 55.1;
		mMastery += 200;
		break;
	default:
		break;
	}
	wp = i;
}

void KeLi::R(int i)
{
	switch (i)
	{
	case 1://魔女
		mDamageIncrease += 30;
		//BP+=15;
		break;
	case 2://渡火
		mDamageIncrease += 35;
		break;
	default:
		break;
	}
	r = i;
}

void KeLi::R1M(int i)
{
    switch (i)
    {
    case 1://攻击
        mAttackPercent += 46.6;
        _maxNumAttackPercent -= 6;
        break;
    case 2://精通
        mMastery += 187;
        break;
    default:
        break;
    }
    r1m = i;
}
//杯主属性选择
void KeLi::R2M(int i)
{
    switch (i)
    {
    case 1://雷
        mDamageIncrease += 46.6;
        break;
    case 2://攻击
        mAttackPercent += 46.6;
        _maxNumAttackPercent -= 6;
        break;
    case 3://精通
        mMastery += 187;
        break;
    default:
        break;
    }
    r2m = i;
}
//头主属性选择
void KeLi::R3M(int i)
{
    switch (i)
    {
    case 1://暴
        mCriticalRate += 31.1;
        _maxNumCriticalRate -= 6;
        break;
    case 2://暴伤
        mCriticalDamage += 62.2;
        _maxNumCriticalDamage -= 6;
        break;
    case 3://精通
        mMastery += 187;
        break;
    default:
        break;
    }
    r3m = i;
}

double KeLi::ExpD()
{
    if (_attributeChanged)
    {
        expD = allAtk() * (1 + CR()) * (1 + DB()) * (1 + SP() + AE()) * 2.0;//全打融化
        _attributeChanged = false;
    }
    return expD;
}

void KeLi::Resolve(int n)
{
	KeLi temp = KeLi(*this);
	int nn = n < 45 ? n : 45;
    for (int i = 0; i <= nn && i <= _maxNumAttackPercent; i++)
    {
        for (int j = 0; j <= nn - i && j <= _maxNumAttackAdd; j++)
        {
            for (int k = 0; k <= nn - i - j && k <= _maxNumCriticalRate; k++)
            {
                for (int l = 0; l <= nn - i - j - k && l <= _maxNumCriticalDamage; l++)
                {
                    if (nn - i - j - k - l <= _maxNumMastery)
                    {
                        Role* comp = new KeLi(temp);
                        comp->assignSubAttributes(i, j, k, l, nn - i - j - k - l);
                        compare(comp);
                        delete comp;
                    }
                }
            }
        }
    }
}
