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
static int kCurR1M = 0;
static int kCurR2M = 0;
static int kCurR3M = 0;
static int kMaxWP[3] = { 0,3,3 };
static int kMaxR[3] = { 0,2,2 };
static int kMaxR1M[3] = { 0,2,2 };
static int kMaxR2M[3] = { 0,3,3 };
static int kMaxR3M[3] = { 0,3,3 };

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
    int currentR1M = kCurR1M;
    int currentR2M = kCurR2M;
    int currentR3M = kCurR3M;

    int maxWeapon = loopMaxInit(currentWeapon,kMaxWP);
    int maxR = loopMaxInit(currentR,kMaxR);
    int maxR1M = loopMaxInit(currentR1M,kMaxR1M);
    int maxR2M = loopMaxInit(currentR2M, kMaxR2M);
    int maxR3M = loopMaxInit(currentR3M, kMaxR3M);

    for (int i = currentWeapon; i < maxWeapon; i++)
    {
        for (int j = currentR; j < maxR; j++)
        {
            for (int k1 = currentR1M; k1 < maxR1M; k1++)
            {
                for (int k2 = currentR2M; k2 < maxR2M; k2++)
                {
                    for (int k3 = currentR3M; k3 < maxR3M; k3++)
                    {
                        f(i, j, k1, k2, k3);
                    }
                }
            }
        }
    }
}

int solve()
{
    bool s1 = bool(kCurWP);
    bool s2 = bool(kCurR);
    bool s3 = bool(kCurR1M);
    bool s4 = bool(kCurR2M);
    bool s5 = bool(kCurR3M);

    //获取角色设置
    if (curRole == 0)
        return 0;
    int chosen = int(s1) + int(s2) + int(s3) + int(s4) + int(s5);

    //表格标题
    cout << "有效词条数  ";
    if (chosen == 5)
    {
        cout << "攻击百分比 " << "攻击数值 " << "暴击率 " << "暴击伤害 ";
    }
    if (chosen < 2)
        return 0;

    doLoop([=](int i, int j, int k1,int k2,int k3) {
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
            cout << k1;
        }
        if (!s4)
        {
            if (!(s1 && s2 && s3))
                cout << '+';
            cout << k2;
        }
        if (!s5)
        {
            if (!(s1 && s2 && s3 && s4))
                cout << '+';
            cout << k3;
        }
        switch (chosen)
        {
        case 2:
            cout << "          ";
            break;
        case 3:
            cout << "            ";
            break;
        case 4:
            cout << "              ";
            break;
        case 5:
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
        doLoop([=, &pRole, &row](int m, int n, int p1,int p2,int p3) {
            newRoleToPointer(pRole);
            pRole->WP(m);
            pRole->R(n);
            pRole->R1M(p1);
            pRole->R2M(p2);
            pRole->R3M(p3);
            pRole->Resolve(i + 1);
            pFinalRole->compare(pRole);


            if (chosen == 5)
            {
                cout << pRole->_nAttackPercent << "        " << pRole->_nAttackAdd << "        " << pRole->_nCriticalRate << "        " << pRole->_nCriticalDamage<<"      "<< pRole->_nMastery << "      ";;
            }

            cout << pRole->ExpD() << "        ";
            delete pRole;
            pRole = nullptr;
            });
        cout << pFinalRole->allAtk() << "     "
            << pFinalRole->mCriticalRate << "     "
            << pFinalRole->mCriticalDamage << endl;
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
    cin >> kCurR1M;
    cin >> kCurR2M;
    cin >> kCurR3M;
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