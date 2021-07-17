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

const int N = 2*(1e5);

bool visit[N+1];
int dist[N+1];

int far(vector<int>* v,int i)
{
    queue<int> q;
    q.push(i);
    visit[i] = 1;
    int el ;
    while(!q.empty())
    {
        el = q.front();
        q.pop();
        
        for(int i : v[el])
        {
            if(!visit[i])
            {
                q.push(i);
                visit[i] = 1;
                dist[i] = dist[el] + 1;
            } 
        }
    }
    
    return el;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<int> tree[n+1];
    
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    int f = far(tree,1);
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    int p = far(tree,f);
    
    cout<<dist[p];

}
