#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[100002];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	
	fill(dist, dist+100001, 0);
	Q.push(n);	
	dist[n]=1;
	
	while(dist[k]==0){
		int cur = Q.front(); Q.pop();
		for(int nxt: {2*cur, cur-1, cur+1}){
			if(nxt<0 || nxt > 100000)	continue;
			if(dist[nxt]!=0)	continue;
			dist[nxt] = dist[cur]+1;
			Q.push(nxt);
		}
	}
	cout<<dist[k]-1;
	return 0;
}