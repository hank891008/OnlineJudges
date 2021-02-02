#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T,cnt=0;
	cin>>T;
	while(T--){
		int n;
		string s;
		cin>>n>>s;
		int ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='#')continue;
			else{
				ans++;
				i+=2;
			}
		}
		cout<<"Case "<<++cnt<<": "<<ans<<endl;
	}
	return 0;
}