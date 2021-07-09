#include <iostream>
using namespace std;
using ll = long long;

ll power(int a,int b)
{
    ll res = 1;

    while(b)
    {
        if(b&1) res *= a;
        a *= a;
    }
    return res;
}
int main()
{
    int a,b;
    cin>>a>>b;

    cout<<power(a,b);
}