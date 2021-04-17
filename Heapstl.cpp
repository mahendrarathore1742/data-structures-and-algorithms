
#include <bits/stdc++.h>


using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>

#define  rep(i,a,b) for(int i=a;i<b;i++)


int main(){

	priority_queue<int,vector<int>> pq;

	pq.push(3);
	pq.push(2);

	pq.push(1);
	pq.pop();
	cout<<pq.top()<<endl;

	priority_queue<int ,vector<int>,greater<int>> q;

	q.push(2);

	cout<<q.top()<<endl;

}