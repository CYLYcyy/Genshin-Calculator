#pragma once
#include"Role.h"

class Role;
class KeQing :public Role
{
public:
	KeQing();
	void WP(int i);//����ѡ��
	void R(int i);//��װѡ��
	void RM(int i);//������ѡ��
	void Resolve(int n);
	int wp;
	int r;
	int rm;
};