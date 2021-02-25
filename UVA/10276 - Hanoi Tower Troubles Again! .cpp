#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(x,y)
#define F first
#define S second
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main(){
	IOS;
	stack<int>s[55];
    int ans[55];
    ans[0] = 0;
    ans[1] = 1;
    int cnt = 1;
    int num = 2;
    s[1].push(1);
    while(cnt<51){
        int flag = 1;
        for(int i=1;i<=cnt;i++){
            int n = s[i].top() + num;
            int m = sqrt(n);
            if(n == m*m){
                flag = 0;
                s[i].push(num);
                num++;
                break;
            }
        }
        if(flag){
            int total = 0;
            for(int i=1;i<=cnt;i++){
                total+=s[i].size();
            }
            ans[cnt] = total;
            cnt++;
            s[cnt].push(num);
            num++;
        }
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n>50||n<0){
            cout<<-1<<endl;
        }
        else{
            cout<<ans[n]<<endl;
        }
    }
	return 0;
}