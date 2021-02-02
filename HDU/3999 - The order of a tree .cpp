#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left,*right;
	node(int v){
		val = v;
		left = NULL;
		right = NULL;
	}
};
typedef node* nodePtr;

nodePtr insert(nodePtr root,int val){
	if(root == NULL){
		nodePtr tmp = new node(val);
		return tmp;
	}
	else{
		if(val>root->val){
			root->right = insert(root->right,val);
		}
		else{
			root->left = insert(root->left,val);
		}
		return root;
	}
}
int f;
void pre(nodePtr root){
	if(root == NULL){
		return;
	}
	else{
		if(f){
			cout<<root->val;
			f = 0;
		}
		else{
			cout<<" "<<root->val;
		}
		pre(root->left);
		pre(root->right);
	}
}
int main(int argc, char const *argv[]){
	int n;
	while(cin>>n){
		nodePtr root = NULL;
		f=1;
		for(int i=0;i<n;i++){
			int val;
			cin>>val;
			root = insert(root,val);
		}
		pre(root);
		cout<<endl;
	}
	return 0;
}