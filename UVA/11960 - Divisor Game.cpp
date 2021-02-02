#include <bits/stdc++.h>
using namespace std;

int arr[1000005],ans[1000005];
int main(int argc, char const *argv[]){
	arr[1]=1;
	for(int i=2;i<=1000000;i++){
		for(int j=1;j<=1000000;j++){
			if(i*j>1000000){break;}
			arr[i*j]++;
		}
	}
	int maxx=0,a;
	for(int i=1;i<=1000000;i++){
		if(maxx<=arr[i]){
			a = i;
			maxx = arr[i];
		}
		ans[i]=a;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}