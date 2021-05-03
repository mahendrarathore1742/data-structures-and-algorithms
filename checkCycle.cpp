#include <bits/stdc++.h>
using namespace  std;


class Cyclecheck{
public:
	bool Cycleforcheck(int s,int V,vector<int> adj[],vector<int> & visited){
		queue<pair<int,int>>q;

		visited[s]=true;
		q.push({s,-1});

		while(!q.empty()){
			int node=q.front().first;
			int par=q.front().second;
			q.pop();

			for(auto it: adj[node]){
				if(!visited[it]){
					visited[it]=true;
					q.push({it,node});
				}
				else if(par!=it)
					return true;
			}
		}
		return false;
	}
public:
	bool isCycle(int V,vector<int> adj[]){
		vector<int> vis(V+1,0);

		for(int i=1;i<=V;i++){
			if(!vis[i]){
				if(Cycleforcheck(i,V,adj,vis)) return false;
			}
		}

		return false;
	}
};


int main(){
	return 0;

	Cyclecheck c;
}
