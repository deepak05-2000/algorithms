#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
using ll=long long;
#define INT_MAX int(1e9 + 1)
#define INT_MIN int(-(1e9 + 1))
#define MOD int(1e9+7)

class Heap{

 vector<int> ar;
 int size;
public:
  Heap(vector<int>& v,int n)
  {
    ar = v;
    size = n;
    Heapify();
  }

  void Heapify()
  {
     int i = (size - 1) / 2;
     for(int j = i;j >= 0;j--)
     {
        HeapifyHelp(j);
     }
  }
  void HeapifyHelp(int i)
  {
    int left = 2*i + 1;
    int right = 2*i + 2;

    int l = left < size ? ar[left] : INT_MIN;
    int r = right < size ? ar[right] : INT_MIN;

    int ind = l > r ? left : right;
    if(max(l,r) > ar[i])
    {
        swap(ar[ind],ar[i]);
        HeapifyHelp(ind);
    }
  }

  int nikaal()
  {
     swap(ar[0],ar[size - 1]);
     int el = ar.back(); ar.pop_back();
     size--;
     HeapifyHelp(0);
     return el;
  }

  void add(int el)
  {
     ar.push_back(el);
     size++;
     int ind = (size - 1);
     int par = (ind - 1) / 2;

     while(ind != 0 && ar[par] < ar[ind])
     {
        swap(ar[ind],ar[par]);
        ind = par; 
        par = (ind - 1) / 2;
     }

  }

  void print()
  {
     for(int i=0;i<size;i++)
        cout<<ar[i]<<" ";
  }

};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> ar = { 5,3,7,2,8,9};
    Heap h(ar,6);
    h.print();
    cout<<'\n'<<h.nikaal()<<'\n';
    h.print() ; cout<<'\n';

    h.add(10);
    h.print();

}
