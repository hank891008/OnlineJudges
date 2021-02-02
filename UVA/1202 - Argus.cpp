#include <bits/stdc++.h>
using namespace std;

int main(){
	string st;
	pair<int,int>p;
	map<int,int>m;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	while(cin>>st&&st[0]!='#'){
		cin>>p.second>>p.first;
		m[p.second]=p.first;
		pq.push(p);
	}
	int t;
	cin>>t;
	while(t--){
		pair<int,int>temp = pq.top();
		pq.pop();
		cout<<temp.second<<endl;
		temp.first+=m[temp.second];
		pq.push(temp);
	}
}