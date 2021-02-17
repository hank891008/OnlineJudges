#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int x,y;
	double dis;
	Edge(int x,int y,double d):x(x),y(y),dis(d){}
	bool operator<(const Edge &rhs)const{
		return dis < rhs.dis;
	}
};
int fa[505];
int s,p;
vector<Edge>v;
void init(int n){
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
}
int findr(int x){return x==fa[x]?fa[x]:x=findr(fa[x]);}

void kuskal(){
	sort(v.begin(),v.end());
	init(p);
	int cnt = 0;
	for(int i=0;i<v.size();i++){
		Edge tmp = v[i];
		int x = findr(v[i].x);
		int y = findr(v[i].y);
		if(x != y){
			cnt++;
			fa[x]=y;
			if(cnt== p-s){
				printf("%.2lf\n", tmp.dis);
				return;
			}
		}
	}
}
void solve(){
	v.clear();
	cin>>s>>p;
	int x[p],y[p];
	for(int i=0;i<p;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<p;i++){
		for(int j=i+1;j<p;j++){
			double d = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
			v.push_back(Edge(i,j,d));
		}
	}
	kuskal();
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}