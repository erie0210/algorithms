#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int vis[502][502];
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};


int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>board[i][j];
		}
	}
	
	int mx = 0;
	int num = 0;
	
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(board[i][j]==0 || vis[i][j])	continue;
			num++;
			queue<pair<int,int>> Q;
			vis[i][j]=1;
			Q.push({i,j});
			
			int area =0;
			while(!Q.empty()){
				area++;
				pair<int,int> cur = Q.front();
				Q.pop();
				
				for(int d=0; d<4; d++){
					int nx = cur.first + dx[d];
					int ny = cur.second + dy[d]; 
					if(nx<0 || nx>=n || ny<0 || ny>=m)	continue;
					if(vis[nx][ny] || board[nx][ny]!=1) continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			
			mx = max(mx, area);
		}
	}
	cout<<num << '\n' << mx;
	
	return 0;
}