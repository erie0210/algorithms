#include <bits/stdc++.h>
using namespace std;

int v,e;
tuple<int,int,int> edge[100002];


vector<int> p(10002, -1);

int find(int x){
	if(p[x]<0)	return x;
	return p[x] = find(p[x]);
}

bool uni(int u,int v){
	u = find(u); v = find(v);
	if(u==v)	return true;
	if(p[u]==p[v])	p[v] = u;
	else p[u]=v;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>v>>e;
	for(int i=0; i<e; i++){
		int a,b,cost;
		cin>>a>>b>>cost;
		edge[i] = {cost,a,b};
	}
	sort(edge,edge+e); //cost가 낮은 순서대로 정렬
	
	int cnt =0;
	int ans =0;
	
	for(int i=0; i<e; i++){
		int a,b,cost;
		tie(cost,a,b)= edge[i];
		if(uni(a,b))	continue;
		ans+=cost;
		cnt++;
		if(cnt==v-1)	break;
	}
	cout<<ans;
	return 0;
}