#include <bits/stdc++.h>
using namespace std;
int main() {
	int c,s,q,cnt=0;
	while(cin>>c>>s>>q){
		if(c==0&&s==0&&q==0){break;}
		if(cnt){
			cout<<endl;
		}
		cout<<"Case #"<<++cnt<<endl;
		int arr[c+1][c+1];
		for(int i=1;i<=c;i++){
			for(int j=1;j<=c;j++){
				arr[i][j]=INT_MAX;
			}
		}
		for(int i=0;i<s;i++){
			int a,b,val;
			cin>>a>>b>>val;
			arr[a][b]=val;
			arr[b][a]=val;
		}
		for(int t=1;t<=c;t++){
			for(int i=1;i<=c;i++){
				for(int j=1;j<=c;j++){
					arr[i][j]=min(arr[i][j],max(arr[i][t],arr[t][j]));
				}
			}
		}
		for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			if(arr[a][b]==INT_MAX){
				cout<<"no path\n";
			}
			else{
				cout<<arr[a][b]<<endl;
			}
		}
	}	
	return 0;
}	