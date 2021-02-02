#include <bits/stdc++.h>
using namespace std;
queue<int>q;
queue<int>teamq[1005];
int main(){
    int team;
    int cnt=0;
    while(cin>>team&&team!=0){
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<team;i++){
            while(!teamq[i].empty()){
                teamq[i].pop();
            }
        }
        map<int,int>m;
        printf("Scenario #%d\n",++cnt);
        int n;
        int a;
        for(int i=0;i<team;i++){
            cin>>n;
            for(int j=0;j<n;j++){
                cin>>a;
                m[a]=i;
            }
        }
        string st;
        while(cin>>st&&st[0]!='S'){
            if(st[0]=='E'){
                cin>>n;
                if(teamq[m[n]].empty()){
                    q.push(m[n]);
                }
                teamq[m[n]].push(n);
            }
            else{
                int now = q.front();
                cout<<teamq[now].front()<<endl;
                teamq[now].pop();
                if(teamq[now].empty()){ 
                    q.pop();
                }
            }
        }
        cout<<endl;
    }

    return 0;
}