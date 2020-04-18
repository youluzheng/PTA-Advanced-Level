#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iostream> 

// 19:52 - 20:30
using namespace std;

int main(){
	int n, sum;
	multiset<int> coins;
	scanf("%d %d", &n, &sum);
	for(int i=0;i<n;i++){
		int m; 
		scanf("%d", &m);
		coins.insert(m);
	}
	for(auto i:coins){
		if(coins.count(sum-i) > 0){
			if(i == sum - i){
				if(coins.count(sum-i) > 1){
					printf("%d %d", i, i);
					return 0;
				}
			}else{
				printf("%d %d", i, sum-i);
				return 0;
			}
		}
		if(i*2 > sum){
			break;
		}
	}
	printf("No Solution");
}
