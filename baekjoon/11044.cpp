#include <bits/stdc++.h>
using namespace std;

int arr[1002];
int s[1002];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
  
	int n; cin>>n;
	for(int i=0; i<n; i++){	cin>>arr[i];	s[i]=arr[i];}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i])	s[i] = max(s[i], s[j]+arr[i]);
		}
	}
	cout<<*max_element(s, s+n);
	// your code goes here
	return 0;
}