#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int>
#define vii vector<pii>
#define rep(i,a,b) for(i=a;i<b;i++)


priority_queue<int,vi,greater<int>> pqmin;
priority_queue<int,vi> pqmax;


void insert(int x){
	if(pqmax.size()==pqmin.size()){
		if(pqmax.size()==0){
			pqmax.push(x);
			return;
		}

		if(x<pqmax.top()){
			pqmax.push(x);
		}
		else{
			pqmin.push(x);
		}

	}else{
		if(pqmax.size()>pqmin.size()){
			if(x>=pqmax.top()){
				pqmin.push(x);
			}else{
				int temp=pqmax.top();
				pqmax.pop();
				pqmin.push(temp);
				pqmax.push(x);
			}
		}
		else{
			if(x<=pqmin.top()){
				pqmax.push(x);
			}
			else{

				int temp=pqmin.top();
				pqmin.pop();
				pqmax.push(temp);
				pqmin.push(x);
			}
		}
	}
}


double finmid(){
	if(pqmin.size()==pqmax.size()){
		return (pqmin.top()+pqmax.top())/2.0;
	}
	else if(pqmax.size()>pqmin.size()){
		return pqmax.top();
	}else{
		return pqmin.top();
	}
	
}

int main(){

	insert(10);
	cout<<finmid()<<endl;

	insert(15);
	cout<<finmid()<<endl;

	insert(21);
	cout<<finmid()<<endl;

	insert(30);
	cout<<finmid()<<endl;

	insert(18);
	cout<<finmid()<<endl;

	insert(19);
	cout<<finmid()<<endl;

	return 0;
}
