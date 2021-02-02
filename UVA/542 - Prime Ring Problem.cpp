#include <bits/stdc++.h>
using namespace std;
int isp[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
bool visited[17];
int arr[17];
int n;
void dfs(int d){
	if((d==n)&&isp[1+arr[n]]){
		cout<<arr[1];
		for(int i=2;i<=n;i++){
			cout<<" "<<arr[i];
		}
		cout<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			if(!visited[i]){
				if(isp[arr[d]+i]){
					arr[d+1]=i;
					visited[i]=true;
					dfs(d+1);
					visited[i]=0;
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int cases=0,p=0;
	while(cin>>n){
		if(p)cout<<endl;
		p=1;
		cout<<"Case "<<++cases<<":\n";
		arr[1]=1;
		visited[1]=true;
		dfs(1);
	}
	return 0;
}
