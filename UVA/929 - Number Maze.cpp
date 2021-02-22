#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
	int dis;
	node(int x, int y, int dis): x(x), y(y), dis(dis){}
	bool operator<(const node& rhs)const{
		return dis>rhs.dis;
	}
};
int maze[1005][1005];
int vis[1000][1000];
int dp[1000][1000];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int row, col;
void dijkstra(){
	priority_queue<node>pq;
	dp[0][0] = maze[0][0];
	pq.push(node(0,0,maze[0][0]));
	while(!pq.empty()){
		node tmp = pq.top();
		pq.pop();
		vis[tmp.y][tmp.x] = true;
		for(int i = 0; i < 4; i++){
			int x = tmp.x + dir[i][0];
			int y = tmp.y + dir[i][1];
			if(x < 0 || x >= col){continue;}
			if(y < 0 || y >= row){continue;}
			if(!vis[y][x]){
				if(dp[y][x]>dp[tmp.y][tmp.x] + maze[y][x]){
					dp[y][x] = dp[tmp.y][tmp.x] + maze[y][x];
					pq.push(node(x,y,dp[y][x]));
				}
			}
		}
	}
	cout << dp[row-1][col-1] << '\n';
}
void solve(){
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> maze[i][j];
			vis[i][j] = 0;
			dp[i][j] = INT_MAX;
		}
	}
	dijkstra();
}
int main(){
	int T;
	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}