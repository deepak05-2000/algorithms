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

vector<bool> p(10000+1,1);

void seive()
{
   p[0] = p[1] = 0; 

   for(int i=2;i<=10000;i++)
   {
      if(p[i] && ll(i*i)<=10000)
      {
         for(int j=i*i;j<=10000;j+=i)
         {
            p[j] = 0;
         }
      }
   }
}
void solve()
{
   int d;
   cin>>d;
   ll p = 1+d;

   int an;
   for(int i=p;i<=10000;i++)
   {
      if(p[i])
      {
         an = i; break;
      }
   }

}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int t;
   cin>>t;

   seive();
   while(t--)
   {
      solve();
   }
}