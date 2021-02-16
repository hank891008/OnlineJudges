#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	string a,b;
	cin>>a>>b;
	int cnta[26]={},cntb[26]={};
	for(int i=0;i<n;i++){
		cnta[a[i]-'a']++;
		cntb[b[i]-'a']++;
	}
	for(int i=0;i<25;i++){
		if(cnta[i]<cntb[i]||(cnta[i]-cntb[i])%k){
			cout<<"No\n";
			return;
		}
		else{
			cnta[i+1]+=cnta[i]-cntb[i];
		}
	}
	cout<<"Yes\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}