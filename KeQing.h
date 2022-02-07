#pragma once
#include"Role.h"

class Role;
class KeQing :public Role
{
public:
	KeQing();
    virtual void WP(int i) override;//武器选择
    virtual void R(int i) override;//套装选择
    virtual void R1M(int i) override;//沙漏主属性选择
    virtual void R2M(int i) override;//杯主属性选择
    virtual void R3M(int i) override;//头主属性选择

    virtual double ExpD() override;
    virtual void Resolve(int n) override;
    virtual ~KeQing();
};
