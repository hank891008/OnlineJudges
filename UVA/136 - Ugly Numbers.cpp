#include <bits/stdc++.h>
using namespace std;
int ugly[]={2,3,5};
int main(int argc, char const *argv[])
{
	priority_queue<long long ,vector<long long >,greater<long long>>pq;
	set<int>s;
	pq.push(1);
	s.insert(1);
	for(int i=1;i<=1500;i++){
		long long  temp=pq.top();
		pq.pop();
		if(i==1500){
			cout<<"The 1500'th ugly number is "<<temp<<"."<<endl;
			break;
		}
		for(int i=0;i<3;i++){
            long long  x=temp*ugly[i];
            if(!s.count(x)){
                s.insert(x);
                pq.push(x);
            }
        }
	}
	return 0;
}