#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		stack<int>s;
		queue<int>q;
		priority_queue<int>pq;
		int sf=2,qf=2,pqf=2;
		int type,val;
		for(int i=0;i<n;i++){
			cin>>type>>val;
			if(type==1){
				s.push(val);
				q.push(val);
				pq.push(val);
			}
			else{
				if(s.empty()){
					sf=0;
				}
				if(q.empty()){
					qf=0;
				}
				if(pq.empty()){
					pqf=0;
				}
				if(!s.empty()&&sf){
					if(s.top()!=val)
						sf=1;
				}
				if(!q.empty()&&qf){
					if(q.front()!=val)
						qf=1;
				}
				if(!pq.empty()&&pqf){
					if(pq.top()!=val)
						pqf=1;
				}
				if(!s.empty())
					s.pop();
				if(!q.empty())
					q.pop();
				if(!pq.empty())
					pq.pop();
			}
		}
		if(sf*qf*pqf>=4){
			cout<<"not sure\n";
		}
		else if(sf*qf*pqf==1||sf*qf*pqf==0){
			cout<<"impossible\n";
		}
		else{
			if(sf==2){
				cout<<"stack\n";
			}
			else if(qf==2){
				cout<<"queue\n";
			}
			else{
				cout<<"priority queue\n";
			}
		}
	}
	return 0;
}