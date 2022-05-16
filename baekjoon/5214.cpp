#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101002];
int vis[101002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k,m; cin>>n>>k>>m;
	for(int i=1; i<=m; i++){
		for(int j=0; j<k; j++){
			int x; cin>>x;
			adj[i+n].push_back(x);
			adj[x].push_back(i+n);
		}
	}
	
	fill(vis, vis+n+m+1, -1);
	
	queue<int> q;
	q.push(1);
	vis[1]=0;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto iter: adj[cur]){
			if(vis[iter]!=-1)	continue;
			q.push(iter);
			vis[iter]=vis[cur]+1;
			// cout<<iter<<' '<<vis[iter]<<'\n';
		}
	}


  if(vis[n] == -1) cout << -1;
  else cout << vis[n]/2 + 1;
  
  
	return 0;
}