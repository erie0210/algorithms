#include <bits/stdc++.h>
using namespace std;
#define MAXX 1001

int N,M,V;
int m[MAXX][MAXX];
bool visited[MAXX];
queue<int> q;



void dfs(int v){
	visited[v]=1;
	cout<<v<<" ";
	for(int i=1; i<=N; i++){
		if(m[v][i]==1 && visited[i]==0){
			dfs(i);
		}
	}
}

void bfs(int v){
	q.push(v);
	visited[v] = 1;
	cout<< v <<" "; 
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		for(int w=1; w<=N; w++){
			if(m[v][w]==1 && visited[w]==0){
				q.push(w);
				visited[w]=1;
				cout<<w<<" "; 
			}	
		}
		
	}
}

int main() {
	
	cin>>N>>M>>V;
	for(int i=0; i<M; i++){
		int a,b;
		cin>>a>>b;
		m[a][b] = 1;
		m[b][a] = 1;
	}
	
	dfs(V);
	cout<<'\n';
	memset(visited,0, sizeof(visited));
	bfs(V);
	return 0;
}