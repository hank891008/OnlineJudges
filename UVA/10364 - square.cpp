#include <bits/stdc++.h>
using namespace std;

int stick[25],used[25],sum,n;
int flag;
bool cmp(int a,int b){return a>b;}

void dfs(int edge,int total,int start){
	if(flag==1){return;}
	else if(total > sum){return;}
	else if(edge==3){flag=1;return;}
	else if(sum==total){dfs(edge+1,0,0);}
	else{
		for(int i=start;i<n;i++){
			if(used[i]==0){
				used[i]=1;
				dfs(edge,total+stick[i],i+1);
				used[i]=0;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		flag=0;
		sum=0;
		int maxx=0;
		memset(used,0,sizeof(used));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>stick[i];
			sum+=stick[i];
			maxx = max(maxx,stick[i]);
		}
		sort(stick,stick+n,cmp);
		if(sum%4!=0||maxx>(sum/4)){
			cout<<"no\n";
			continue;
		}
		sum/=4;
		dfs(0,0,0);
		if(flag) cout<<"yes\n";
		else cout<<"no\n";

	}
	return 0;
}