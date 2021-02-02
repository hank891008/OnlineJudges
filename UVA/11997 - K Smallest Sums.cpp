#include <bits/stdc++.h>
using namespace std;

struct Data{
	int sum;
	int i;
	bool operator<(const Data &data)const{
		return sum>data.sum;
	}
};
int main(int argc, char const *argv[])
{
	int a[805],b[805];
	int k;
	while(cin>>k){
		for(int i=0;i<k;i++){
			cin>>a[i];
		}
		sort(a,a+k);
		for(int i=1;i<k;i++){
			for(int j=0;j<k;j++){
				cin>>b[j];
			}
			sort(b,b+k);
			priority_queue<Data>pq;
			for(int i=0;i<k;i++){
				pq.push(Data{a[i]+b[0],0});
			}
			for(int i=0;i<k;i++){
				Data tmp = pq.top();
				pq.pop();
				a[i]=tmp.sum;
				
				if(tmp.i<k){
					pq.push(Data{tmp.sum-b[tmp.i]+b[tmp.i+1],tmp.i+1});
				}
			}
		}
		for(int i=0;i<k;i++){
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
    }
	return 0;
}