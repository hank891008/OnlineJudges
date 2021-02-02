#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		int arr[t];
		for(int i=0;i<t;i++){
			cin>>arr[i];
		}
		int max=0;
		set<int>s;
		int L=0,R=0;
		int count=0;
		while(L<t&&R<t){
			//cout<<"L="<<L<<" R="<<R<<endl;
			if(!s.count(arr[R])){
				//cout<<"~\n";
				s.insert(arr[R++]);
				if(max<R-L){
					max=R-L;
				}
			}
			else{
				s.erase(arr[L++]);
			}
		}
		cout<<max<<endl;
	}
	return 0;
}