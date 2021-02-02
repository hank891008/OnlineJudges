#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int kase=0;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x[n+1],pos[k+1]={0};
		x[1]=1;
		x[2]=2;
		x[3]=3;
		for(int i=4;i<=n;i++){
			x[i] = (x[i-1] + x[i-2] + x[i-3]) % m + 1;
		}
		int cnt = 0,ans = INT_MAX,used[k+1]={0};
		for(int i=1;i<=n;i++){
			if(cnt==k){
				int maxx = INT_MIN,minn = INT_MAX;
				for(int i=1;i<=k;i++){
					maxx = max(maxx,pos[i]);
					minn = min(minn,pos[i]);
				}
				ans = min(ans,maxx-minn);
			}
			if(x[i] >= 1 && x[i] <= k){
				pos[x[i]] = i;
				if(!used[x[i]]){
					cnt++;
				}
				used[x[i]]=1;
			}
		}
		if(cnt==k){
			printf("Case %d: %d\n",++kase,ans+1);
		}
		else{
			printf("Case %d: sequence nai\n",++kase);
		}
	}
}