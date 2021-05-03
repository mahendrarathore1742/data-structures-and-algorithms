#include <iostream>
using namespace  std;



int maxsubarray(int a[],int n){
	int maxsum=0;
	int cursum=0;
	for (int i = 0; i < n; i++)
	{
			
			cursum=cursum+a[i];

			if(cursum>maxsum){
				maxsum=cursum;
			}

			if(cursum<0){
				cursum=0;
			}


	}

	return maxsum;
}

int main(){
	int n=6;
	int a[]={-5,4,6,-3,4,-1};
	cout<<maxsubarray(a,n)<<endl;
	return 0;
}