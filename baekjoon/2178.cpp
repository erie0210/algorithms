#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;
string mm[102];
int dist[102][102];

queue<pair<int,int>> Q;

int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++)cin>>mm[i];
	for(int i=0; i<n; i++) memset(dist[i], 0, sizeof(dist[i]));

	Q.push({0,0});
	dist[0][0]=0;
	
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){
			int nextR = cur.first+dx[i];
			int nextC = cur.second+dy[i];
			if(nextR<0 || nextR >=n || nextC <0 || nextC>=m)	continue;
			if(mm[nextR][nextC]!='1')	continue;
			if(dist[nextR][nextC]!=0)	continue;
			Q.push({nextR, nextC});
			dist[nextR][nextC]= dist[cur.first][cur.second]+1;
		}
	}
	cout<<dist[n-1][m-1]+1;
	return 0;
}




