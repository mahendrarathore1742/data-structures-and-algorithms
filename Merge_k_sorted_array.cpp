#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)


int main(){

	int k;
	cin>>k;

	vector<vector<int>> a(k);

	rep(i,0,k)
		{
			int size;
			cin>>size;
			a[i]=vector<int>(size);

			rep(j,0,size){

				cin>>a[i][j];
			}
		}

		vector<int> idex(k,0);

		priority_queue<pii ,vector<pii>,greater<pii>> pq;

		rep(i,0,k){
			pq.push({a[i][0],i});
		}

		vi ans;

		while(!pq.empty()){
			pii x=pq.top();
			pq.pop();


			ans.push_back(x.ff);


			if(idex[x.ss]+1 < a[x.ss].size()){

				pq.push({a[x.ss][idex[x.ss]+1],x.ss});

			}
			idex[x.ss]+=1;
		}
		rep(i,0,ans.size()){
			cout<<ans[i]<<endl;
		}
		cout<<endl;
		return 0;
}