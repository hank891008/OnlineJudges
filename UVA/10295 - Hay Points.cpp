#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n;
	string st;
	int value;
	cin>>m>>n;
	map<string,int>ma;
	map<string,int>::iterator it;
	for(int i=0;i<m;i++){
		cin>>st>>value;
		ma.insert(make_pair(st,value));
	}
	
	for(int i=0;i<n;i++){
		int sum=0;
		while(cin>>st&&st!="."){
			it = ma.find(st);
			if(it!=ma.end()){
				sum+=ma[st];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}