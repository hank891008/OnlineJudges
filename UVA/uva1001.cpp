#include <bits/stdc++.h>
using namespace std;
double dis(int x1, int y1, int z1, int x2, int y2, int z2){
	double x = x1 - x2, y = y1 - y2, z = z1 - z2;
	return sqrt(x * x + y * y + z * z);
}
struct item{
	int x, y, z, r;
};
int main(){
	int n;
	int cnt = 0;
	while(cin >> n && n != -1){
		item arr[n + 2];
		for(int i = 1; i <= n; i++){
			cin >> arr[i].x >> arr[i].y >> arr[i].z >> arr[i].r;
		}
		cin >> arr[0].x >> arr[0].y >> arr[0].z;
		arr[0].r = 0;
		cin >> arr[n + 1].x >> arr[n + 1].y >> arr[n + 1].z;
		arr[n + 1].r = 0;
		double dp[n + 2][n + 2];
		for(int i = 0; i < n + 2; i++){
			for(int j = 0; j < n + 2; j++){
				dp[i][j] = INT_MAX;
			}
		}
		for(int i = 0; i < n + 2; i++){
			for(int j = 0; j < n + 2; j++){
				double di = dis(arr[i].x, arr[i].y, arr[i].z, arr[j].x, arr[j].y, arr[j].z);
				if(di <= arr[i].r + arr[j].r)
					dp[i][j] = 0;
				else
					dp[i][j] = di - arr[i].r - arr[j].r;

			}
		}
		for(int k = 0; k < n + 2; k++){
			for(int i = 0; i < n + 2; i++){
				for(int j = 0; j < n + 2; j++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		printf("Cheese %d: Travel time = %d sec\n", ++cnt, (int)round(dp[0][n + 1] * 10));
	}
	return 0;
}