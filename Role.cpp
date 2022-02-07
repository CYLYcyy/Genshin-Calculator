#include "Role.h"

Role::~Role()
{

}

void Role::WP(int i)
{
    wp = i;
}

void Role::R(int i)
{
    mAttackAdd += 311;//羽
    r = i;
}

void Role::R1M(int i)
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

void Role::R2M(int i)
{
    switch (i)
    {
    case 1://属性伤害
        mDamageIncrease += 46.6;
        break;
    case 2://攻击
        mAttackPercent += 46.6;
        _maxNumAttackPercent -= 6;
        break;
    case 3://精通
        mMastery += 187;
        break;
    case 4://物理伤害
        mDamageIncrease += 58.3;
        break;
    default:
        break;
    }
    r2m = i;
}

void Role::R3M(int i)
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

//总面板攻击
double Role::allAtk() const
{
    return (mBaseAttack * (1 + mAttackPercent / 100) + mAttackAdd);
}
//暴击收益
double Role::CR() const
{
    if (mCriticalRate < 100)
        return mCriticalRate / 100 * mCriticalDamage / 100;
    else
        return mCriticalDamage / 100;
}
//增伤收益
double Role::DB() const
{
    return mIncreasePercent / 100 * mDamageIncrease / 100;
}
//精通收益(剧变反应需再乘以2.4)
double Role::SP() const
{
    return 25 * mMastery / (9 * (mMastery + 1400));
}

//伤害期望
double Role::ExpD()
{
    if (_attributeChanged)
    {
        expD = allAtk() * (1 + CR()) * (1 + DB());
        _attributeChanged = false;
    }
    return expD;
}

//直接替换为更优;
void Role::compare(Role* compare)
{
    if (compare->ExpD() > ExpD())
    {
        *this = *compare;
    }
}

void Role::assignSubAttributes(int nAtkPercent, int nAtkAdd, int nCritical, int nCriDamage, int nMystery)
{
    auto checkNum = [](int& needAdd, int curNum, int maxNum)
    {
        if (curNum + needAdd > maxNum)
            needAdd = maxNum - curNum;
    };
    checkNum(nAtkPercent, _nAttackPercent,  _maxNumAttackPercent);
    checkNum(nAtkAdd,     _nAttackAdd,      _maxNumAttackAdd);
    checkNum(nCritical,   _nCriticalRate,   _maxNumCriticalRate);
    checkNum(nCriDamage,  _nCriticalDamage, _maxNumCriticalDamage);
    checkNum(nMystery,    _nMastery,        _maxNumMastery);

    mAttackPercent += (nAtkPercent * 4.1);
    _nAttackPercent += nAtkPercent;

    mAttackAdd += (nAtkAdd * 14.0);
    _nAttackAdd += nAtkAdd;

    mCriticalRate += (nCritical * 2.7);
    _nCriticalRate += nCritical;

    mCriticalDamage += (nCriDamage * 5.4);
    _nCriticalDamage += nCriDamage;

    mMastery += (nMystery * 23.0);
    _nMastery += nMystery;

    _attributeChanged = true;
    
    return;
}

//最佳属性求解,n为有效副属性点数
void Role::Resolve(int n)
{
    Role temp = Role(*this);
    int nn = n < 45 ? n : 45;
    for (int i = 0; i <= nn && i <= _maxNumAttackPercent; i++)
    {
        for (int j = 0; j <= nn - i && i <= _maxNumAttackAdd; j++)
        {
            for (int k = 0; k <= nn - i - j && i <= _maxNumCriticalRate; k++)
            {
                for (int l = 0; k <= nn - i - j-k && i <= _maxNumCriticalDamage; l++)
                {
                    if (nn - i - j - k-l <= _maxNumMastery)
                    {
                        Role* comp = new Role(temp);
                        comp->assignSubAttributes(i, j, k, l, nn - i - j - k - l);
                        compare(comp);
                        delete comp;
                    }
                }
            }
        }
    }
}

