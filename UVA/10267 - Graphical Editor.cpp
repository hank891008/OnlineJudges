#include <bits/stdc++.h>
using namespace std;
int m,n;
char arr[255][255];
char c[2];
void I(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]='O';
		}
	}
}
void C(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]='O';
		}
	}
}
void L(){
	int x,y;
	cin>>x>>y>>c;
	arr[y][x]=c[0];
}
void V(){
	int x,y1,y2;
	cin>>x>>y1>>y2>>c;
	if(y1>y2)swap(y1,y2);
	for(int i=y1;i<=y2;i++){
		arr[i][x]=c[0];
	}
}
void H(){
	int x1,x2,y;
	cin>>x1>>x2>>y>>c;
	if(x1>x2)swap(x1,x2);
	for(int j=x1;j<=x2;j++){
		arr[y][j]=c[0];
	}
}
void K(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2>>c;
	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	for(int i=y1;i<=y2;i++){
		for(int j=x1;j<=x2;j++){
			arr[i][j]=c[0];
		}
	}
}
void F(int x,int y,char color){
	if(y<1||y>n||x<1||x>m||arr[y][x]!=color)
		return;
	arr[y][x]=c[0];
	F(x-1,y,color);
	F(x+1,y,color);
	F(x,y-1,color);
	F(x,y+1,color);
}
int main(int argc, char const *argv[]){
	char word[2];
	while(cin>>word){
		if(word[0]=='X')break;
		else if(word[0]=='I')
			I();
		else if(word[0]=='C')
			C();
		else if(word[0]=='L')
			L();
		else if(word[0]=='V')
			V();
		else if(word[0]=='H')
			H();
		else if(word[0]=='K')
			K();
		else if(word[0]=='F'){
			int x,y;
			cin>>x>>y>>c;
			if(arr[y][x]==c[0])continue;
			else{
				F(x,y,arr[y][x]);
			}
		}
		else if(word[0]=='S'){
			string st;
			cin>>st;
			cout<<st<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cout<<char(arr[i][j]);
				}
				cout<<'\n';
			}
		}

	}
	return 0;
}