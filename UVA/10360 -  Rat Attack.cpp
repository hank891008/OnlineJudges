#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int rat;
		cin>>rat;
		memset(arr,0,sizeof(arr));
		while(rat--){
			int x,y,r;
			cin>>x>>y>>r;
			for(int i=x-n;i<=x+n;i++){
				for(int j=y-n;j<=y+n;j++){
					if(i>=0&&i<=1024&&j>=0&&j<=1024){
						arr[i][j]+=r;
					}
				}
			}
		}
		int nowx,nowy,nowr=0;
		for(int i=0;i<=1024;i++){
			for(int j=0;j<=1024;j++){
				if(arr[i][j]>nowr){
					nowr = arr[i][j];
					nowx = i;
					nowy = j;
				}
			}
		}
		cout<<nowx<<" "<<nowy<<" "<<nowr<<endl;
	}
	return 0;
}