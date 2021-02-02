#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	string st;
	set<string>s;
	while(cin>>st){
		string temp;
		for(int i=0;i<st.size();i++){
			if(isalpha(st[i])){
				temp+=tolower(st[i]);
			}
			else{
				s.insert(temp);
				temp="";
			}
		}
		if(temp.size()>0)
			s.insert(temp);
	}
	set<string>::iterator it=s.begin();
	it++;
	for(;it!=s.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}