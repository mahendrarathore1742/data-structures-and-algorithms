#include <iostream>

using namespace  std;


int findfeasible(int boards[],int n,int limite){

	int sum=0,painters=1;

	for (int i = 0; i <n; i++)
	{
	sum+=boards[i];
	if(sum>limite){
		sum=boards[i];
		painters++;
	}
	}

	return painters;
}

int painters_Partition(int boards[],int n,int m){

	int tottalength=0,k=0;
	for (int i = 0; i<n; i++)
	{

		k=max(k,boards[i]);
		tottalength+=boards[i];
	}

	int low=k,high=tottalength;

	while(low<high){
		int mid=(low+high)/2;

		int painters=findfeasible(boards,n,mid);
		if(painters<=m){
			high=mid;
		}
		else{
			low=mid+1;
		}

	}

	return low;
}


int main(){

	int arr[]={10,20,30,40};
	int n=4;
	int  m=2;
	cout<<painters_Partition(arr,n,m)<<endl;

	return 0;
}