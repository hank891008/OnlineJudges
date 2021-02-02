#include <bits/stdc++.h>
using namespace std;
int queen[92][8],chess[8];
int c=0;
void dfs(int step){
    if(step==8){
        for(int i=0;i<8;i++){
            queen[c][i]=chess[i];
        }
        c++;
    }
    else{
        for(int i=0;i<8;i++){	//chess[steps]=i;
            for(int j=0;j<step;j++){
                if(chess[j]==i||abs(step-j)==abs(chess[j]-i))break;
                else if(j==step-1){
                    chess[step]=i;
                    dfs(step+1);
                }
            }
        }
    }
}
int main(){
    for(int i=0;i<8;i++){
        chess[0]=i;
        dfs(1);
    }
    int t;
    cin>>t;
    while(t--){
        int cnt=1;
        int r,c;
        cin>>r>>c;
        cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        for(int i=0;i<92;i++){
            if(queen[i][c-1]==r-1){
                cout<<setw(2)<<setfill(' ')<<cnt++<<"      ";
				for(int j=0;j<8;j++){
					if(j==0)cout<<queen[i][0]+1;
					else cout<<" "<<queen[i][j]+1;
				}
				cout<<endl;
            }
        }
        if(t)
            cout<<endl;
    }
}