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
	int t;
	cin >> t;
	int ans[32768] = {0,0,0,1};
	for(int i = 4; i <= 32767; i++){
		ans[i] = ans[i-1] + (i - 1) / 2;
	}
	while(t--){
		int n;
		cin >> n;
		cout << ans[n] << '\n';
	}
	return 0;
}
