#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
	int x,y,w;
	bool operator<(const Edge &b)const {
    	return b.w>w;
    }
};
priority_queue<Edge>E;
int fa[10005];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int findr(int x){
	return x==fa[x]?fa[x]:fa[x]=findr(fa[x]);
}
void unite(int x,int y){
	x==findr(x);
	y==findr(y);
	fa[x]=y;
}
int kruskal(){
	int cost=0;
	struct Edge tmp;
	while(!E.empty()){
		tmp=E.top();
		E.pop();
		int x=findr(tmp.x);
		int y=findr(tmp.y);
		if(x==y){
			cost+=tmp.w;
			continue;
		}
		else{
			unite(x,y);
		}
	}
	return cost;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		struct Edge t;
		init(n);
		while(m--){
			cin>>t.x>>t.y>>t.w;
			E.push(t);
		}
		int ans=kruskal();
		cout<<ans<<endl;
	}
	cin>>t;
	return 0;
}