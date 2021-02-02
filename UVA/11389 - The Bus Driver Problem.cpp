#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,d,r;
	int morning[100],night[100];
	while(cin>>n>>d>>r&&(n*d*r)){
		int f=0;
		for(int i=0;i<n;i++){
			cin>>morning[i];
		}
		for(int i=0;i<n;i++){
			cin>>night[i];
		}
		sort(morning,morning+n);
		sort(night,night+n);
		reverse(night,night+n);
		for(int i=0;i<n;i++){
			if(morning[i]+night[i]>d){
				f+=(morning[i]+night[i]-d)*r;
			}
		}
		cout<<f<<endl;
	}
	return 0;
}