#include <bits/stdc++.h>
using namespace std;

char s[128];
bool check(int l,int r,int n){
	for(int i=1;i<l;i++){
		if(s[i]==s[l]){
			return 1;
		}
	}
	for(int i=r+1;i<=n;i++){
		if(s[i]==s[r]){
			return 1;
		}
	}
	return 0;
}
void solve(){
	int n,q;
	cin>>n>>q;
	scanf("%s",s+1);
	while(q--){
		int l,r;
		cin>>l>>r;
		if(check(l, r, n)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}

}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}