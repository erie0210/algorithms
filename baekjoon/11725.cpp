#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100002];
int vis[100002];

void dfs(int cur){
	for(auto iter: adj[cur]){
		if(vis[iter]!=0)	continue;
		vis[iter] = cur;
		dfs(iter);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;
	int len = n;
	while(n--){
		int u,v; cin>>u>>v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	dfs(1);
	for(int i=2; i<=len; i++){
		cout<<vis[i]<<'\n';
	}
	return 0;
}