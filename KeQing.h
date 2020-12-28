#pragma once
#include"Role.h"

class Role;
class KeQing :public Role
{
public:
	KeQing();
	void WP(int i);//武器选择
	void R(int i);//套装选择
	void RM(int i);//主属性选择
	void Resolve(int n);
	int wp;
	int r;
	int rm;
};