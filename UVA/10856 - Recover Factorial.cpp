#include <bits/stdc++.h>
using namespace std;
int fac[3000000];
void solve(){
	fill(fac, fac + 3000000, 1);
	fac[0]=0;
	fac[1]=0;
	for(int i=2;i<=3000000;i++){
		if(fac[i]==1){
			for(int j=2;i*j<=3000000;j++){
				fac[i*j]=fac[i]+fac[j];
			}
		}
	}
	for(int i=2;i<=3000000;i++){
		fac[i] +=fac[i-1];
	}

}
int main(int argc, char const *argv[])
{
	solve();
	int n;
	int cnt=0;
	while(cin>>n&&n>=0){
		if(n==0){
			printf("Case %d: 0!\n",++cnt);
			continue;
		}
		int f=1;
		int l=0,r=3000000;
		while(l<=r){
			int m = (l+r)/2;
			if(fac[m]>n){
				r=m-1;
				continue;
			}
			else if(fac[m]==n){
				printf("Case %d: %d!\n",++cnt,m);
				f=0;
				break;
			}
			else{
				l = m+1;
				continue;
			}
		}
		if(f){
			printf("Case %d: Not possible.\n",++cnt);
		}

	}
	return 0;
}