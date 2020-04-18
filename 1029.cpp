#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 16:36 - 16:54 
using namespace std;

int n1, n2;

int main(){
	vector<int> a;
	vector<int> b;
	scanf("%d", &n1);
	for(int i=0;i<n1;i++){
		int t;
		scanf("%d", &t);
		a.push_back(t);
	}
	scanf("%d", &n2);
	for(int i=0;i<n2;i++){
		int t;
		scanf("%d", &t);
		b.push_back(t);
	}
	int tar = (n1 + n2 - 1)/2;
	a.insert(a.end(), b.begin(), b.end());
	sort(a.begin(), a.end());
	printf("%d", a[tar]);
}
