#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 17:28 -  
using namespace std;

int n;
int seq[100010];
int min_[100010];
int max_[100010];

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &seq[i]);
	}
	if(n == 1){
		printf("1\n%d", seq[0]);
		return 0;
	}
	int min = 0x7fffffff;
	int max = 0x80000000;
	for(int i=0;i<n;i++){
		if(seq[i] > max){
			max = seq[i];
		}
		max_[i] = max;
	}
	for(int i=n-1;i>=0;i--){
		if(seq[i] < min){
			min = seq[i];
		}
		min_[i] = min;
	}
	vector<int> tar;
	if(seq[0] <= min_[1]){
		tar.push_back(seq[0]);
	}
	for(int i=1;i<n-1;i++){
		if(seq[i] <= min_[i+1] && seq[i] >= max_[i-1]){
			tar.push_back(seq[i]);
		}
	}
	if(seq[n-1] >= max_[n-2]){
		tar.push_back(seq[n-1]);
	}
	if(tar.size() == 0){
		printf("0\n\n");
		return 0;
	}
	printf("%d\n", tar.size());
	for(int i=0;i<tar.size()-1;i++){
		printf("%d ", tar[i]);
	}	
	printf("%d", tar[tar.size()-1]);
}
