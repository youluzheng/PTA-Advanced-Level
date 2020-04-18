#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 19:30 -  19:40
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> num;
	map<int, int> mp;
	for(int i=0;i<n;i++){
		int m;
		scanf("%d", &m);
		num.push_back(m);
		mp[m]++;
	}
	int i = 0;
	for(i=0;i<num.size();i++){
		if(mp[num[i]] < 2){
			printf("%d", num[i]);
			return 0;
		}
	}
	if(i == num.size()){
		printf("None");
	}
}
