#include <bits/stdc++.h>
using namespace std;

vector<int>fa;
int flag=0;
void init(int n){
	fa.resize(n+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int findr(int x){
	if(x==fa[x]){
		return fa[x];
	}
	else{
		return x = findr(fa[x]);
	}
}
void unite(int a,int b){
	a = findr(a);
	b = findr(b);
	fa[a] = b;
}
bool same(int a,int b){
	a = findr(a);
	b = findr(b);
	if(a==b){return 1;}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		if(flag){
			cout<<endl;
		}
		flag=1;
		int n;
		cin>>n;
		init(n);
		int right=0,wrong=0;
		char line[1000];
		char word;
		int a,b;
		cin.ignore();
		while(gets(line)){
			if(line[0]=='\0'){
				break;
			}
			else{
				sscanf(line,"%c %d %d",&word,&a,&b);
				if(word=='c'){
					unite(a,b);
				}
				else{
					if(same(a,b)){
						right++;
					}
					else{
						wrong++;
					}
				}
			}
		}
		cout<<right<<","<<wrong<<endl;
	}
	return 0;
}