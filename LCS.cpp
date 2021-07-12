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

    string a,b;
    cin>>a;
    cin>>b;

    int n = a.length(); int m = b.length();

    int dp[n+1][m+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]!=b[j-1])
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-1]+1,dp[i-1][j]);
            }

        }
    }

    cout<<m-dp[n][m];

}
