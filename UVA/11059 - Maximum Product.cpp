#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int cnt=0;
	while(cin>>n){
		int s[18];
		long long max = 0;
		for(int i=0;i<n;i++)cin>>s[i];
		for(int i=0;i<n;i++){
			long long  sum=1;
			for(int j=i;j<n;j++){
				sum*=s[j];
				if(max<sum)max=sum;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",++cnt,max);
	}
	return 0;
}