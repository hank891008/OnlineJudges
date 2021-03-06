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
	long long dp[70][70][2] = {0};
	dp[1][0][0] = dp[1][1][1] = 1;
	for(long long i = 2; i <= 65; i++){
		dp[i][0][0] = dp[i-1][1][1] + dp[i-1][0][0];
		for(long long j = 1; j <= i; j++){
			dp[i][j][0] = dp[i-1][j+1][1] + dp[i-1][j][0];
			dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j-1][0];
		}
	}
	long long n,m;
	while(cin >> n >> m && n >= 0 && m >= 0){
		cout << dp[n][m][0] + dp[n][m][1] << '\n';
	}
	return 0;
}
