#include<iostream>
#include<cmath>
#include<string>
#include "Role.h"
#include "KeQing.h"
#include "KeLi.h"
using namespace std;

static int curRole = 0;
static int kCurWP = 0;
static int kCurR = 0;
static int kCurRM = 0;
static int kMaxWP[3] = {0,3,5};
static int kMaxR[3] = {0,2,2};
static int kMaxRM[3] = {0,4,4};

void newRoleToPointer(Role*& pointer)
{
    if(pointer)
        delete pointer;

    switch (curRole) {
    case 1:
        pointer = new KeQing;
        break;
    case 2:
        pointer = new KeLi;
        break;
    default:
        pointer = nullptr;
        break;
    }
}

int loopMaxInit(int& loopMin,int* max)
{
    if (loopMin != 0)
    {
        return loopMin + 1;
    }
    else
    {
        loopMin = 1;
        return max[curRole]+1;
    }
}

template <typename F>
void doLoop(F const& f) {
    int currentWeapon= kCurWP;
    int currentR = kCurR;
    int currentRM = kCurRM;

    int maxWeapon = loopMaxInit(currentWeapon,kMaxWP);
    int maxR = loopMaxInit(currentR,kMaxR);
    int maxRM = loopMaxInit(currentRM,kMaxRM);

    for (int i = currentWeapon; i < maxWeapon; i++)
    {
        for (int j = currentR; j < maxR; j++)
        {
            for (int k = currentRM; k < maxRM; k++)
            {
                f(i, j, k);
            }
        }
    }
}

int solve()
{
    bool s1 = bool(kCurWP);
    bool s2 = bool(kCurR);
    bool s3 = bool(kCurRM);


    //获取角色设置
    if (curRole == 0)
        return 0;
    int chosen = int(s1) + int(s2) + int(s3);

    //表格标题
    cout << "有效词条数  ";
    if (chosen == 3)
    {
        cout << "攻击百分比 " << "攻击数值 " << "暴击率 " << "暴击伤害 ";
    }
    doLoop([=](int i, int j, int k) {
        if (!s1)
            cout << i;
        if (!s2)
        {
            if(!s1)
                cout<< '+';
            cout << j;
        }
        if (!s3)
        {
            if(!(s1&&s2))
                cout << '+';
            cout << k;
        }
        switch (chosen)
        {
        case 0:
            cout << "          ";
            break;
        case 1:
            cout << "            ";
            break;
        case 2:
            cout << "              ";
            break;
        case 3:
            cout << "伤害期望  ";
            break;
        default:
            break;
        }
        });
    cout << "面板攻击     "
        << "暴击率     "
        << "暴击伤害      " << endl;

    //表格内容
    for (int i = 0; i < 45; i++)
    {
        cout << i + 1 << "           ";

        Role* pFinalRole = nullptr;
        Role* pRole = nullptr;
        newRoleToPointer(pFinalRole);
        int row = 1;
        doLoop([=, &pRole, &row](int m, int n, int p) {
            newRoleToPointer(pRole);
            pRole->WP(m);
            pRole->R(n);
            pRole->RM(p);
            pRole->Resolve(i + 1);
            pFinalRole->compare(pRole);


            if (chosen == 3)
            {
                cout << pRole->nabp << "        " << pRole->naba << "        " << pRole->ncr << "        " << pRole->ncd<<"      ";
            }

            cout << pRole->ExpD() << "        ";
            delete pRole;
            pRole = nullptr;
            });
        cout << pFinalRole->allAtk() << "     "
            << pFinalRole->CriRate << "     "
            << pFinalRole->CriDamage << endl;
        delete pFinalRole;
        pFinalRole = nullptr;
    }
}

void IO()
{
    cout << "选择角色：1.刻晴 2.可莉\n";
    cin >> curRole;
    switch (curRole)
    {
    case 1:
        cout << "刻晴：\n武器：0.备选,1.匣里龙吟,2.天空,3.风鹰剑" << endl;
        cout << "套装：0.备选,1.如雷+角斗,2.平雷" << endl;
        cout << "主属性：0.备选,1.雷暴,2.雷爆伤,3.攻暴,4.攻爆伤" << endl;
        break;
    default:
        break;
    }
    cout << "选择武器、套装、主属性：";
    cin >> kCurWP;
    cin >> kCurR;
    cin >> kCurRM;
}

int main()
{
    while (true)
    {
        IO();
        solve();
        cout << "是否继续";
        cin >> curRole;
        system("CLS");
    }
}