#include <bits/stdc++.h>
using namespace std;

int cnt;
map<string,int>m;
int ID(string city){
	if(m.count(city)){
		return m[city];
	}
	else{
		m[city]=cnt++;
		return m[city];
	}
}
struct Edge{
	bool operator<(
	int x,y,w;const Edge& rhs)const{
		return w<rhs.w;
	}
};

priority_queue<Edge>E;
int fa[205];
void init(int n){
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
}
int findr(int x){
	return (x==fa[x])?fa[x]:findr(fa[x]);
}
void unite(int x,int y){
	x = findr(x);
	y = findr(y);
	fa[x]=y;
}
int kruskal(int a,int b){
	int cost;
	while(!E.empty()){
		Edge tmp = E.top();
		E.pop();
		if(findr(a)==findr(b)){
			return cost;
		}
		else{
			cost = tmp.w;
			unite(tmp.x,tmp.y);
		}
	}
	return cost;
}
int main(){
	int n,r,c=0;
	while(cin>>n>>r&&n&&r){
		cnt=0;
		m.clear();
		init(n);
		Edge t;
		string c1,c2;
		for(int i=0;i<r;i++){
			int w;
			cin>>c1>>c2>>w;
			t.x = ID(c1);
			t.y = ID(c2);
			t.w = w;
			E.push(t);
		}
		cin>>c1>>c2;
		cout<<"Scebario #"<<++c<<'\n'<<kruskal(ID(c1),ID(c2))<<"\n\n";
	}
	return 0;
}