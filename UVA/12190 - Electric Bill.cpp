#include <bits/stdc++.h>
using namespace std;
int de;
int arr[]={0,200,29900,4979900};
int chw(int p){
	if(p>arr[0]&&p<=arr[1]){
		return p/2;
	}
	else if(p>arr[1]&&p<=arr[2]){
		return (p-200)/3+100;
	}
	else if(p>arr[2]&&p<=arr[3]){
		return (p-29900)/5+10000;
	}
	else return (p-4979900)/7+1000000;
}
int price(int d){
	if(d>0&&d<=100){
		return d*2;
	}
	else if(d>100&&d<=10000){
		return (d-100)*3+200;
	}
	else if(d>10000&&d<=1000000){
		return (d-10000)*5+29900;
	}
	else return (d-1000000)*7+4979900;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		de = chw(a);
		int l=0,r=de;
		int val;
		while(l<=r){
			int m = (l+r)/2;
			int me=price(m),nei=price(de-m);
			if(nei-me<b){
				r=m;
			}
			else if(nei-me>b){
				l =m+1; 
			}
			else{
				val=me;
				break;
			}
		}
		cout<<val<<endl;
	}
	return 0;
}