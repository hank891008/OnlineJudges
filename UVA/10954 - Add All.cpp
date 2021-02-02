#include <bits/stdc++.h>
using namespace std;

struct mapp
{
	map<int,int> ma;
};
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int cnt;
	cin>>cnt;
	while(cnt--){
		int n;
		cin>>n;
		int arr[n];
		int total=0;
		for(int i=1;i<=n;i++){
			total+=i;
		}
		struct mapp m[total];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int temp=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				for(int k=i;k<=j;k++){
					m[temp].ma[arr[k]]++;
				}
				temp++;
			}
		}
		int max=0;
		for(int i=0;i<total;i++){
			map<int,int> ::iterator it;
			int sum=0;
			int count=0;
			int flag=1;
			for(it=m[i].ma.begin();it!=m[i].ma.end();it++){
				if(it->second==1)count++;
				else{
					flag=0;
					break;
				}
				if(flag){
					if(count>max){
						max=count;
					}
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}