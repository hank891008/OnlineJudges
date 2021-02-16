#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long d,k;
	cin>>d>>k;
	long long x=0,y=0;
	int flag;
	char last='y';
	while(x*x+y*y<=d*d){
		if(last=='y'){
			last='x';
			x+=k;
			flag=1;
		}
		else{
			last='y';
			y+=k;
			flag=0;
		}
	}
	if(flag==1){
		cout<<"Utkarsh\n";
	}
	else{
		cout<<"Ashish\n";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}