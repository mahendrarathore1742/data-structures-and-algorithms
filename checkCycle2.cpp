#include <bits/stdc++.h>
using namespace  std;

class CheckCycle{
public:
	bool checkForCycle(int node,int parent,vector<int> &vis,vector<int> adj[]){

		vis[node]=1;
		for(auto it: adj[node]){
			if(vis[it]==0){
				if(checkForCycle(it,node,vis,adj)) return true;
			}
			else if(it!=parent) return true;
		}
		return false;
	}

public:
	bool isCycle(int V,vector<int> adj[]){
		vector<int> vis(V+1,0);

		for(int i=1;i<=V;i++){
			if(!vis[i]){
				if(checkForCycle(i,-1,vis,adj)) return true;
			}
		}
		return false;
	}
};

int main(){
	CheckCycle c;
}