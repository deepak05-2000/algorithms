#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;
using ll=long long;
#define INT_MAX int(1e9 + 1)
#define INT_MIN int(-(1e9 + 1))
#define MOD int(1e9+7)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll dp[n];
    dp[n-1] = 1;

    ll res = -1;
    for(int i=n-2;i>=0;i--)
    {
        ll ans = -1;
        for(int j =i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                ans = max(ans,dp[j]);
            }
        }
        dp[i] = ans==-1?1:ans+1;
        res = max(res,dp[i]);
    }

    cout<<res;
}
