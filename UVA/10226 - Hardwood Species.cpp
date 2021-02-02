#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int f=0;
	char tmp[2];
	gets(tmp);
	while(n--){
		if(f){
			cout<<endl;
		}
		string s;
		if(!f)
			getline(cin,s);
		f=1;
		map<string,int>m;
		map<string,int>::iterator it;  
		int sum=0;
		while(getline(cin,s)){
			if(s=="")break;
			m[s]++;
			sum++;
		}

		for(it=m.begin();it!=m.end();it++){
			cout<<it->first<<" "<<fixed<<setprecision(4)<<(double)it->second/sum*100<<endl;
		}
	}
	return 0;
}