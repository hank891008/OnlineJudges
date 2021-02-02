#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n!=0){
        scanf("%*c");
        int arr[10005],index[10005];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            index[arr[i]]=i;
        }
        int f=0,next;
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n;j++){
                next = 2*arr[j]-arr[i];
                if(next>=0&&next<n&&index[2*arr[j]-arr[i]]>j){
                    f=1;
                    break;
                }
            }
            if(f)break;
        }
        if(f)cout<<"no\n";
        else cout<<"yes\n";
    }
}