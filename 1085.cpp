#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 16:00 - 
using namespace std;

struct node{
	int min;
	int max;
	int count;
};

int n, p;

int main(){
	scanf("%d %d", &n, &p);
	int seq[n];
	for(int i=0;i<n;i++){
		scanf("%d", &seq[i]);
	}
	sort(seq, seq+n);
	int max_count = 1;
	int i = 0, j = n-1;
	for(;j>=0 && (long long)seq[i] * p < seq[j];j--);
	max_count = max(j - i + 1, max_count);
	for(;i<n;i++){
		for(;j<n && seq[j] <= (long long)seq[i] * p;j++);
		max_count = max(j-i, max_count);
		// 剩下的已经比count小 
		if(n - i <= max_count){
			break;
		}
	}
	printf("%d", max_count);
}
