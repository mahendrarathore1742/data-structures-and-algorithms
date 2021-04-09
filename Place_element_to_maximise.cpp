#include <iostream>
#include<algorithm>

using namespace  std;


bool isFesible(int mid,int arr[],int n,int k){
	int pos=arr[0],element=1;

	for (int i = 1; i <n; i++)
	{
		if(arr[i]-pos>=mid){
			pos=arr[i];
			element++;

			if(element==k){
				return true;
			}
		}
	}

	return false;
}

int largestMinDistance(int arr[],int n, int k){
	sort(arr,arr+n);
	int res=-1;
	int left=1,right=arr[n-1];
	while(left<right){
		int mid=(left+right)/2;
		if(isFesible(mid,arr,n,k)){
			res=max(res,mid);
			left=mid+1;
		}else{
			right=mid;
		}
	}
	return res;
}

int main(){

		int arr[]={1,2,8,4,9};
		int n=5;
		int k=3;
		cout<<largestMinDistance(arr,n,k)<<endl;

	return 0;
}