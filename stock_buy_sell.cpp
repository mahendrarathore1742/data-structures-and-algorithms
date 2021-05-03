#include <iostream>
using namespace std;


int MaxProfit(int arr[],int n){

	int maxProfit=0;
	int minsofar=arr[0];

	for (int i = 0; i < n; ++i)
	{
		
		minsofar=min(minsofar,arr[i]);
		int profit=arr[i]-minsofar;

		maxProfit=max(maxProfit,profit);

	}

	return maxProfit;

}


int main(){

	int arr[]={3,1,4,8,7,2,5};

	cout<<MaxProfit(arr,7)<<endl;

	return 0;
}