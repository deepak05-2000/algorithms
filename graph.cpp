#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
using ll=long long;
#define INT_MAX int(1e9 + 1)


int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};
struct Node 
{
	int first;
	int second;
	ll dist;
	
	Node(int a,int b,int d)
	{
		dist = d;
		first = a;
		second = b;
		
	}
};

ll bfs(char** a,int x,int y,int n,int m)
{
	ll len = INT_MAX;
	queue<Node> q;
	q.push(Node(x,y,0));

	int key =0;
	while(!q.empty())
	{
		Node el = q.front();
		
		q.pop();
		for(int d = 0;d<4;d++)
		{
			if(el.first+dx[d]<0 || el.first+dx[d]>=n || el.second+dy[d]<0 || el.second+dy[d]>=m)
				continue;
			else
			{
				if(a[el.first+dx[d]][el.second+dy[d]]=='.')
				{
					Node n = Node(el.first+dx[d],el.second+dy[d],el.dist+1);
					q.push(n);
				}
				else if(a[el.first+dx[d]][el.second+dy[d]]=='B')
					return min(len,el.dist+1);
			}
		}
	}
	return len;
}
int main()
{

   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   int n,m;
   cin>>n>>m;

   char** a = new char*[n];
   for(int i=0;i<n;i++)
     a[i] = new char[m];

   int x ,y;
   for(int i=0;i<n;i++)
   {
   	  for(int j=0;j<m;j++)
   	  {
	    cin>>a[i][j];
	   	if(a[i][j]=='A')
	   	{
	   	  x = i; y = j;
	   	}
   	  }
   }

   ll ans = bfs(a,x,y,n,m);

   if(ans!=INT_MAX)
   {
   	  cout<<"YES\n";
   	  cout<<ans;
   }
   

}