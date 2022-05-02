#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100002];

int binary(int target){
	int le=0, ri=n-1;
	while(le<=ri){
		int mid = (le+ri)/2;
		if(arr[mid]<target)	le = mid+1;
		else if(arr[mid]>target)	ri = mid-1;
		else	return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n; i++)	cin>>arr[i];
	sort(arr,arr+n);
	
	cin>>m;
	while(m--){
		int t;
		cin>>t;
		cout<<binary(t)<<'\n';
	}
	return 0;
}