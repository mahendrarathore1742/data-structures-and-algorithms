#include <iostream>

using namespace  std;


int maxProfit(int arr[],int n){

	int profit=0;
	for (int i = 0; i <n ; ++i)
	{
		
		if(arr[i]>arr[i-1]){
			profit+=arr[i]-arr[i-1];

		}
	}
	return profit;
}


int main(){


	int arr[]={5,2,6,1,4,7,3,6};
	cout<<maxProfit(arr,8)<<endl;
	return 0;
}