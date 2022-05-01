#include <bits/stdc++.h>
using namespace std;

int v,e,st;
vector<pair<int,int>> adj[20002];
const int INF = 0x3f3f3f3f;
int d[20002];

void print(int d[7]){
		for(int c=0; c<7; c++){
			cout<<d[c]<<' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>v>>e>>st;
	fill(d, d+v+1, INF);
	// memset(d, INF, sizeof(d+v+1));

	while(e--){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({w, v});
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	d[st]=0;
	pq.push({d[st], st});
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.second]!=cur.first)	continue;
		for(auto nxt: adj[cur.second]){
			if(d[nxt.second] <= d[cur.second]+nxt.first)	continue;
			d[nxt.second] = d[cur.second]+nxt.first;
			pq.push({d[nxt.second], nxt.second});
		}
	}

	
	for(int i=1; i<=v; i++){
		if(d[i]==INF)	cout<<"INF"<<'\n';
		else cout<<d[i]<<'\n';
	}
	return 0;
}