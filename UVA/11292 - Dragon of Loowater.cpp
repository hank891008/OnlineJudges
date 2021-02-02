#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,dragon[20005],knight[20005];
	while(cin>>n>>m&&n*m){
		bool check = true;
		for(int i=0;i<n;i++){
			cin>>dragon[i];
		}
		for(int i=0;i<m;i++){
			cin>>knight[i];
		}
		sort(dragon,dragon+n);
		sort(knight,knight+m);
		//reverse(knight,knight+m);

		int j=0;
		int total=0;
		for(int i=0;i<n;i++){
			int check1=false;
			while(j<m){
				if(knight[j]<dragon[i])j++;
				else{
					total+=knight[j];
					j++;
					check1 = true;
					break;
				}
			}
			if(check1)continue;
			if(j==m)cout<<"Loowater is doomed!\n";
			check = false;
			break;
		}
		if(check){
			cout<<total<<endl;
		}
	}
	return 0;
}