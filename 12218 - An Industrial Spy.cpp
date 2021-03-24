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
	string st;
	set<int>s;
	int t;
	cin >> t;
	while(t--){
		cin >> st;
		sort(st.begin(), st.end());
		int ans;
		s.clear();
		do{
			ans = 0;
			for(int i = st.size()-1,j = 1; i >=0; i--,j *= 10){
				ans += (st[i] - '0') * j;
				int flag = 1;
				if(ans == 1 || ans == 0 || ans % 2 == 0 && ans != 2){
					continue;
				}
				if(ans == 2){
			
				}
				else{
					for(int i = 3; i <= sqrt(ans); i += 2){
						if(ans % i == 0){
							flag = 0;
							break;
						}
					}
				}
				if(flag){
					s.insert(ans);
				}
			}
		}while(next_permutation(st.begin(), st.end()));
		cout << s.size() << '\n';
	}
	return 0;
}