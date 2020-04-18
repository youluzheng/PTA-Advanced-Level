#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<iostream> 

// 19:32 - 20:50 
using namespace std;

int n;
map<int, int> mp;

void init(){
	mp[0] = 0;
	for(int i=1;i<10;i++){
		mp[i] = 1;
	}
	mp[10] = 1;
	for(int i=100;i<1000000001;i*=10){
		int x = i/10;
		mp[i] = 10*mp[x] + x;
	}
}

int getLevel(int n){
	int level = 0;
	int x = n;
	while(x >= 10){
		x /= 10;
		level++;
	}
	return level;
}

int getCount(int n, int level){
	if(n == 0){
		return 0;
	}
	int count = 0;
	int f = n/pow(10, level);
	if(f > 1){
		count += f*mp[pow(10, level)] + pow(10, level);
	}else{
		count += mp[pow(10, level)] + 1 + n%(int)pow(10, level);
	}
	return count; 
}

int main(){
	init();
	scanf("%d", &n);
	int count = 0;
	while(n >= 10){
		int level = getLevel(n);
		count += getN(n, level);
		n %= (int)pow(10, level);
	}
	count += mp[n];
	printf("%d", count);
}
