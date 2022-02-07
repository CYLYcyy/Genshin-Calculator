#include "KeQing.h"

KeQing::~KeQing()
{

}

KeQing::KeQing()
{
	mBaseAttack = 323;
	mCriticalRate += 15;//大招
	mCriticalDamage += 38.4;//突破
}

void KeQing::WP(int i)
{
	switch (i)
	{
	case 1://匣里龙吟
		mBaseAttack += 510;
		mAttackPercent += 41.3;
		mDamageIncrease += 20;
		break;
	case 2://天空
		mBaseAttack += 608;
		mCriticalRate += 4;
		mAtkSpeed += 10;
		break;
	case 3://风鹰剑
		mBaseAttack += 674;
		mAttackPercent += 20;
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
	case 1://如雷2+角斗2
		mDamageIncrease += 15;
		mAttackPercent += 18;
		break;
	case 2://平雷
		mDamageIncrease += 35;
		break;
	default:
		break;
	}

    mAttackAdd += 311;//羽

	r = i;
}
//沙漏主属性选择
void KeQing::R1M(int i)
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
void KeQing::R2M(int i)
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
void KeQing::R3M(int i)
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

double KeQing::ExpD()
{
    return Role::ExpD() * (1 + mAtkSpeed / 100);
}

void KeQing::Resolve(int n)
{
	KeQing temp = KeQing(*this);
	int nn = n < 45 ? n : 45;
    for (int i = 0; i <= nn && i <= _maxNumAttackPercent; i++)
    {
        for (int j = 0; j <= nn - i && i <= _maxNumAttackAdd; j++)
        {
            for (int k = 0; k <= nn - i - j && i <= _maxNumCriticalRate; k++)
            {
                for (int l = 0; l <= nn - i - j - k && i <= _maxNumCriticalDamage; l++)
                {
                    if (nn - i - j - k - l <= _maxNumMastery)
                    {
                        Role* comp = new KeQing(temp);
                        comp->assignSubAttributes(i, j, k, l, nn - i - j - k - l);
                        compare(comp);
                        delete comp;
                    }
                }
            }
        }
    }
}
