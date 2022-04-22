#include <bits/stdc++.h>
using namespace std;

int m, n;
int dist[1002][1002];
int mm[1002][1002];

bool isValid(int r, int c){	return(r>=0 && r<m && c>=0 && c<n);}

bool checkAllVisited(int mm[1002][1002]){
	for(int r=0; r<m; r++){
		for(int c=0; c<n; c++){
			if(dist[r][c]==0)	return false;
		}
	}
	return true;
}

void print(int dist[1002][1002]){
	for(int r=0; r<m; r++){
		for(int c=0; c<n; c++){
			cout<<dist[r][c]<<' ';
		}cout<<'\n';
	}
}

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
queue<pair<int,int>> Q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			dist[i][j]=-1;
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>mm[i][j];
			if(mm[i][j]==1){
				Q.push({i,j});
				dist[i][j]=1;
			}
			if(mm[i][j]==-1){
				dist[i][j]=0;
			}
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int nextR = cur.first + dr[i];
			int nextC = cur.second + dc[i];
			
			if(!isValid(nextR, nextC))	continue;
			if(mm[nextR][nextC] == -1)	continue;	
			if(dist[nextR][nextC]!= -1)	continue;
			
			Q.push({nextR, nextC});
			dist[nextR][nextC]=dist[cur.first][cur.second]+1;
		}
	}
	
	int maxVal = -1;
	int minVal = 987654321;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			maxVal = max(maxVal, dist[i][j]);
			minVal = min(minVal, dist[i][j]);
		}
	}
	if(minVal==-1)	cout<<-1;
	else cout<<maxVal-1;
	return 0;
}