#include <bits/stdc++.h>
using namespace std;
int c,s,q;
struct Edge{
	int x,y,w;
	bool operator<(const Edge &b)const{
		return w>b.w;
	}
};
priority_queue<Edge>E;
priority_queue<Edge>T;
int fa[1005];
void init(){
	for(int i=1;i<=c;i++){
		fa[i]=i;
	}
}
int findr(int x){
	return x==fa[x]?fa[x]:fa[x]=findr(fa[x]);
}
void unite(int x,int y){
	x = findr(x);
	y = findr(y);
	fa[x]=y;
}
int kruskal(){
	int a,b,cost=0;
	cin>>a>>b;
	struct Edge tmp;
	while(!T.empty()){
		tmp = T.top();
		T.pop();
		int x = findr(tmp.x),y = findr(tmp.y);
		if(x==y){
			continue;
		}
		else{
			unite(x,y);
			cost = max(cost,tmp.w);
		}
		if(findr(a)==findr(b)){
			break;
		}
	}
	if(findr(a)!=findr(b)){
		return 0;
	}
	return cost;
}
int main() {
	int cnt=0;
	while(cin>>c>>s>>q&&c!=0&&s!=0&&q!=0){
		if(cnt){
			cout<<endl;
		}
		cout<<"Case #"<<++cnt<<endl;
		while(!E.empty()){
			E.pop();
		}
		init();
		struct Edge t;
		while(s--){
			cin>>t.x>>t.y>>t.w;
			E.push(t);
		}
		while(q--){
			T=E;
			init();
			int ans=kruskal();
			if(ans){
				cout<<ans<<endl;
			}
			else{
				cout<<"no path\n";
			}
		}
	}
	return 0;
}