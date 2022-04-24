#include <bits/stdc++.h>
using namespace std;

int R,C;
string mm[1002];
int vis[1002][1002];
int Fvis[1002][1002];

queue<pair<int,int>> Q;
queue<pair<int,int>> FQ;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool isValid(int r, int c){	return(r>=0 && r<R && c>=0 && c<C);}

void print(int mm[1002][1002]){
	for(int r=0; r<R; r++){
		for(int c=0; c<C; c++){
			cout<<mm[r][c]<<' ';
		}cout<<'\n';
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>R>>C;
	
	for(int i=0; i<R; i++)	cin>>mm[i];
	
	for (int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(mm[i][j]=='J'){
				Q.push({i,j});
				vis[i][j]=1;
			}
			if(mm[i][j]=='F'){
				FQ.push({i,j});
				Fvis[i][j]=1;
			}
		}
	}
	
	while(!FQ.empty()){
		auto cur = FQ.front(); FQ.pop();
		for(int i=0; i<4; i++){
			int nextR = cur.first + dx[i];
			int nextC = cur.second + dy[i];
			if(!isValid(nextR, nextC))	continue;
			if(Fvis[nextR][nextC]>=1)	continue;
			if(mm[nextR][nextC]=='#')	continue;
			Fvis[nextR][nextC] = Fvis[cur.first][cur.second]+1;
			FQ.push({nextR,nextC});
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int nextR = cur.first + dx[i];
			int nextC = cur.second + dy[i];
			if(!isValid(nextR, nextC)){
				cout<<vis[cur.first][cur.second];
				return 0;
			}
			if(vis[nextR][nextC]>=1)	continue;
			if(mm[nextR][nextC]=='#')	continue;
			if(Fvis[nextR][nextC]!=0 && Fvis[nextR][nextC] <= vis[cur.first][cur.second]+1)	continue;
			Q.push({nextR, nextC});
			vis[nextR][nextC]= vis[cur.first][cur.second]+1;
		}
	}
	
	cout<<"IMPOSSIBLE";
	return 0;
}