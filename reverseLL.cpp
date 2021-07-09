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

struct Node
{
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};
Node* n = NULL;
Node* h = NULL;

void reverse(Node* s,Node* t)
{
	if(t->next==NULL)
	{
		h = t;
		t->next = s;
		return ;
	}
	reverse(t,t->next);
	t->next = s;
	return ;
}

Node* reverseIter(Node* head)
{
	Node* pre = NULL;
	Node* curr = head,*n;

	while(curr!=NULL)
	{
		n = curr->next;
		curr->next = pre;
		pre = curr;
		curr = n;
	}
	return pre;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Node* head = NULL;
	Node* temp;
	for(int i=1;i<=10;i++)
	{
		if(head==NULL)
		{
			head = new Node(i);
			temp = head;
		}
		else
		{
			temp->next = new Node(i);
			temp = temp->next;
		}
	}

	//reverse(n,head);   // Recursive

	Node* tem = reverseIter(head);
	while(tem!=NULL)
	{
		cout<<tem->data<<" ";
		tem = tem->next;
	}
}
