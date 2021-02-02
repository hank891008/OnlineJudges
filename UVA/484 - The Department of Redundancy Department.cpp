#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long  n;
	map<long long,long long>m;
	vector<long long>v;
	while(cin>>n){
		if(m.find(n)==m.end()){
			m[n]=1;
			v.push_back(n);
		}
		else
			m[n]++;
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "<<m[v[i]]<<endl;
	}
	
	return 0;
}