#pragma once
#include<iostream>
using namespace std;

class Role
{
public:
	Role()
		:Atk(0), AtkBonusPer(0), AtkBonusAdd(0), Inc(0), per(0), CriRate(5), CriDamage(50){}
	//攻击力,攻击力百分比,攻击力数值,属伤加成,属伤占比,暴击率,暴击伤害
	Role(double a, double abp, double aba, double i, double p, double cr, double cd)
		:Atk(a), AtkBonusPer(abp), AtkBonusAdd(aba), Inc(i), per(p), CriRate(cr), CriDamage(cd){}

	//伤害期望
	double ExpD() const;

	//直接替换为更优;
	void compare(const Role& compare);

	Role Iabp(int n);
	Role Iaba(int n);
	Role Icr(int n);
	Role Icd(int n);

	//最佳属性求解,n为有效副属性点数
	void Resolve(int n);

	double Atk;//基础攻击
	double AtkBonusPer;//基础攻击加成%
	double AtkBonusAdd;//攻击力提高(死之羽,班尼特,食物)
	double Inc;//增伤%
	double per;//被增伤占比%(若物理角色全打物伤,属性角色全打属伤,则收益为100)
	double CriRate;//暴击率(双冰,岩主大招,食物)
	double CriDamage;//暴击伤害

	int nabp = 0;//攻击百分比条数
	int naba = 0;//攻击数值条数
	int ncr = 0;//暴击率条数
	int ncd = 0;//暴击伤害条数

	int Maxnabp = 24;//最大攻击百分比条数
	int Maxnaba = 24;//最大攻击数值条数
	int Maxncr = 30;//最大暴击率条数
	int Maxncd = 30;//最大暴击伤害条数
};