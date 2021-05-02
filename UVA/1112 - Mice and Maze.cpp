#include <bits/stdc++.h>
using namespace std;

int main(){
	int kase;
	cin >> kase;
	while(kase--){
		int n, e, t, m;
		cin >> n >> e >> t >> m;
		int dp[n + 1][n + 1];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = 1e5;
				}
			}
		}
		int a, b, ti;
		for(int i = 0; i < m; i++){
			cin >> a >> b >> ti;
			dp[a][b] = ti;
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(dp[i][e] <= t){
				cnt++;
			}
		}
		cout << cnt << '\n';
		if(kase){
			cout << '\n';
		}
	}
}