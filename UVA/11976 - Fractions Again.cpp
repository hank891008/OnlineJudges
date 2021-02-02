#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		vector <pair<int,int>>v;
		for(int y=n+1;y<=2*n;y++){
			if((y*n)%(y-n)==0){
				v.push_back(make_pair(((y*n)/(y-n)),y));
			}
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++){
			printf("1/%d = 1/%d + 1/%d\n",n,v[i].first,v[i].second);
		}

	}
	return 0;
}