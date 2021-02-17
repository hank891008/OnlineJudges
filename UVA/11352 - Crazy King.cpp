#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n, m;
int a[105][105],ax,ay,bx,by;
int pos[][2] = {-2,-1,-2,1,2,-1,2,1,-1,-2,-1,2,1,-2,1,2};
int d[][2] = {-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};

bool ok(int i, int j){
	if(i >= 0 && i < n && j >=0 && j < m)return 1;
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		string st[n];
		memset(a,0,sizeof(a));
		for(int i = 0; i < n; i++){
			cin>>st[i];
		}
		for(int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if(st[i][j] == 'A'){
					ax = i;
					ay = j;
				}
				else if(st[i][j] == 'B'){
					bx = i;
					by = j;
				}
				else if(st[i][j] == 'Z'){
					a[i][j] = -1;
					for(int k = 0; k < 8; k++){
						int x = i + pos[k][0], y = j + pos[k][1];
						if(ok(x,y)){
							a[x][y] = -1;
						}
					}
				}
			}
		}
		a[ax][ay] = 0;
		a[bx][by] = 0;
		int ans=0;
		queue<pair<int,int>>q;
		pair<int,int>tmp;
		q.push(make_pair(ax,ay));
		int f=0;
		while(!q.empty()){
			if(f){
				break;
			}
			tmp = q.front();
			q.pop();
			for(int k = 0; k < 8; k++){
				if(f){
					break;
				}
				int x = tmp.F + d[k][0], y = tmp.S + d[k][1];
				if(ok(x,y) && a[x][y] == 0){
					a[x][y] = a[tmp.F][tmp.S] + 1;
					if (x == bx&&y == by){
						ans = a[x][y];
						f = 1;
					}
					q.push(make_pair(x,y));
				}
			}
		}
		if (ans)printf("Minimal possible length of a trip is %d\n", ans);
		else printf("King Peter, you can't go now!\n");
	}
	return 0;
}