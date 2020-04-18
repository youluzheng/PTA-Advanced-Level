#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

#define MAXN 101
#define null NULL
#define debug printf("-catch-\n");

struct node{
	int value;
	node* left;
	node* right;
	node(int _value){
		value = _value;
		left = null;
		right = null;
	}
	node(int _value, node* _left, node* _right){
		value = _value;
		left = _left;
		right = _right;
	}
};

bool cmp(node a, node b) {
	
}

void show(){
	printf("---show---\n");

	printf("---show end---\n");
}

void show1(){
	printf("---show1---\n");

	printf("---show1 end---\n");
}


void toString(node* s) {
	printf("%c ", s->value);
}

void print(vector<int> s){
	int i=0;
	for(i=0;i<s.size()-1;i++){
		printf("%d ", s[i]);
	}
	printf("%d", s[i]);
}

void pre(node* root){
	if(root == null){
		return ;
	}
	printf("%c", root->value);
	pre(root->left);
	pre(root->right);
}

void mid(node* root){
	if(root == null){
		return ;
	}
	mid(root->left);
	printf("%c", root->value);
	mid(root->right); 
}

void level(node* root, vector<int> &result){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* n = q.front();
		result.push_back(n->value);
		q.pop();
		if(n->left != null){
			q.push(n->left);
		}
		if(n->right != null){
			q.push(n->right);
		}
	}
}

//1 24578 36
// 4 2 758 1 3 6
// 1  2 3 45678
node* create(vector<int> mid, vector<int> post){
	if(mid.empty()){
		return null;
	}
	int a = post[post.size()-1];
	vector<int> mid_left = vector<int>(mid.begin(), find(mid.begin(), mid.end(), a));
	vector<int> mid_right = vector<int>(find(mid.begin(), mid.end(), a)+1, mid.end());
	vector<int> post_left = vector<int>(post.begin(), post.begin()+mid_left.size());
	vector<int> post_right = vector<int>(post.begin()+mid_left.size(), post.end()-1);
	node* left = create(mid_left, post_left);
	node* right = create(mid_right, post_right);
	node* root = new node(a, left, right);
	return root;
}

int main() {
	int n;
	vector<int> mid;
	vector<int> post;
	scanf("%d", &n);
	int a;
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		post.push_back(a);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		mid.push_back(a);
	}
	node* root = create(mid, post);
	vector<int> result;
	level(root, result);
	print(result);
}
