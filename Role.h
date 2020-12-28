#pragma once
#include<iostream>
using namespace std;

class Role
{
public:
	Role()
		:Atk(0), AtkBonusPer(0), AtkBonusAdd(0), Inc(0), per(0), CriRate(5), CriDamage(50){}
	//������,�������ٷֱ�,��������ֵ,���˼ӳ�,����ռ��,������,�����˺�
	Role(double a, double abp, double aba, double i, double p, double cr, double cd)
		:Atk(a), AtkBonusPer(abp), AtkBonusAdd(aba), Inc(i), per(p), CriRate(cr), CriDamage(cd){}

	//�˺�����
	double ExpD() const;

	//ֱ���滻Ϊ����;
	void compare(const Role& compare);

	Role Iabp(int n);
	Role Iaba(int n);
	Role Icr(int n);
	Role Icd(int n);

	//����������,nΪ��Ч�����Ե���
	void Resolve(int n);

	double Atk;//��������
	double AtkBonusPer;//���������ӳ�%
	double AtkBonusAdd;//���������(��֮��,������,ʳ��)
	double Inc;//����%
	double per;//������ռ��%(�������ɫȫ������,���Խ�ɫȫ������,������Ϊ100)
	double CriRate;//������(˫��,��������,ʳ��)
	double CriDamage;//�����˺�

	int nabp = 0;//�����ٷֱ�����
	int naba = 0;//������ֵ����
	int ncr = 0;//����������
	int ncd = 0;//�����˺�����

	int Maxnabp = 24;//��󹥻��ٷֱ�����
	int Maxnaba = 24;//��󹥻���ֵ����
	int Maxncr = 30;//��󱩻�������
	int Maxncd = 30;//��󱩻��˺�����
};