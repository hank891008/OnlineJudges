#include <bits/stdc++.h>
using namespace std;
int pos[8][2] = { {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
int chess[8][8];
bool check(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}
int main(){
	map<char, int>Map;
	Map['a'] = 0;
	Map['b'] = 1;
	Map['c'] = 2;
	Map['d'] = 3;
	Map['e'] = 4;
	Map['f'] = 5;
	Map['g'] = 6;
	Map['h'] = 7;
	string st1, st2;
	while(cin >> st1 >> st2){
		if(st1 == st2){
			printf("To get from %s to %s takes %d knight moves.\n", st1.c_str(), st1.c_str(), 0);
			continue;
		}
		pair<int, int>kn1, kn2;
		kn1 = make_pair(Map[st1[0]], st1[1] - '1');
		kn2 = make_pair(Map[st2[0]], st2[1] - '1');
		memset(chess, 0, sizeof(chess));
		queue<pair<int, int>>q;
		q.emplace(kn1);
		pair<int, int>tmp;
		while(!q.empty()){
			tmp = q.front();	q.pop();
			for(int i = 0; i < 8; i++){
				int x = tmp.first + pos[i][0];
				int y = tmp.second + pos[i][1];
				if(check(x, y) && chess[x][y] == 0){
					chess[x][y] = chess[tmp.first][tmp.second] + 1;
					q.emplace(make_pair(x, y));
				}
			}
			if(chess[kn2.first][kn2.second]){
				break;
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", st1.c_str(), st2.c_str(), chess[kn2.first][kn2.second]);
	}
}
