#include <bits/stdc++.h>
using namespace  std;

int main(){
	int n=4,m=5;
	
	vector<int> adj[n+1];
	for (int i = 0; i <m; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}


	
	
	return 0;
}