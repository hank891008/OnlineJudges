#include <bits/stdc++.h>
using namespace std;
int n,m;
int f=0;
void dfs(int now,int jump){
	if(f){return;}
	if(now==m){
		f=1;
		return;
	}
		if(now+jump<=n){dfs(now+jump,jump+2);}
		if(now-jump>0){dfs(now-jump,jump+2);}
}
int main(){
	while(cin>>n>>m&&n!=0&&m!=0){
		f=0;
		if(n>=49){
			f=1;
		}
		dfs(1,3);
		if(f){
			cout<<"Let me try!\n";
		}
		else{
			cout<<"Don't make fun of me!\n";
		}
	}
	return 0;
}