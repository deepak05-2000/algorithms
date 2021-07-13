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

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp;
    
    dp.push_back(a[0]);

    for(int i=1;i<n;i++)
    {
        if(a[i]>dp.back())
        {
            dp.push_back(a[i]);
        }
        if(a[i]<dp.back())
        {
            int pos = distance(dp.begin(),upper_bound(dp.begin(),dp.end(),a[i]));
            if(dp[pos-1]!=a[i]) 
                dp[pos] = a[i];
        }
    }

    cout<<dp.size();

}
