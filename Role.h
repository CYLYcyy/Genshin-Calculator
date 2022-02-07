#ifndef Role_H
#define Role_H

class Role
{
public:
    Role()
        :mBaseAttack(0)
        ,mAttackPercent(0)
        ,mAttackAdd(0)
        ,mDamageIncrease(0)
        ,mIncreasePercent(100)
        ,mCriticalRate(5)
        ,mCriticalDamage(50) {}
    
    //攻击力,攻击力百分比,攻击力数值,属伤加成,属伤占比,暴击率,暴击伤害
    Role(double a, double abp, double aba, double i, double p, double cr, double cd)
        :mBaseAttack(a)
        ,mAttackPercent(abp)
        ,mAttackAdd(aba)
        ,mDamageIncrease(i)
        ,mIncreasePercent(p)
        ,mCriticalRate(cr)
        ,mCriticalDamage(cd){}
    
    virtual ~Role();

    virtual void WP(int i);//武器选择
    virtual void R(int i);//套装选择
    virtual void R1M(int i);//沙主属性
    virtual void R2M(int i);//杯主属性
    virtual void R3M(int i);//头主属性

    //总面板攻击
    virtual double allAtk() const;
    //暴击收益
    virtual double CR() const;
    //增伤收益
    virtual double DB() const;
    //精通收益(剧变反应需再乘以2.4)
    virtual double SP() const;
    //伤害期望
    virtual double ExpD();

    //直接替换为更优;
    virtual void compare(Role* compare);

    //最佳属性求解,n为有效副属性点数
    virtual void Resolve(int n);

    virtual void assignSubAttributes(int nAtkPercent, int nAtkAdd, int nCritical, int nCriDamage, int nMystery);

    double mBaseAttack;       //基础攻击
    double mAttackPercent;    //基础攻击加成%
    double mAttackAdd;        //攻击力提高(死之羽,班尼特,食物)
    double mDamageIncrease;   //增伤%
    double mIncreasePercent;  //被增伤占比%(若物理角色全打物伤,属性角色全打属伤,则收益为100)
    double mCriticalRate;     //暴击率(双冰,岩主大招,食物)
    double mCriticalDamage;   //暴击伤害
    double mMastery = 0;      //元素精通
    double mAtkSpeed = 0;     //攻速加成

    int _nAttackPercent  = 0;//攻击百分比条数
    int _nAttackAdd      = 0;//攻击数值条数
    int _nCriticalRate   = 0;//暴击率条数
    int _nCriticalDamage = 0;//暴击伤害条数
    int _nMastery        = 0;//元素精通条数

    int _maxNumAttackPercent  = 30;//最大攻击百分比条数
    int _maxNumAttackAdd      = 30;//最大攻击数值条数
    int _maxNumCriticalRate   = 30;//最大暴击率条数
    int _maxNumCriticalDamage = 30;//最大暴击伤害条数
    int _maxNumMastery        = 30;//最大元素精通条数

    int wp = 0;
    int r = 0;
    int r1m = 0;
    int r2m = 0;
    int r3m = 0;

    double expD = 0.0;
    bool _attributeChanged = false;
};
#endif// Role_H
