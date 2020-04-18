#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 13:57 - 14:43
using namespace std;

int n;
vector<int> vec;
map<int, int> mp;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		vec.push_back(t);
		mp[t] = i;
	}
	vector<int> v_copy = vec;
	sort(v_copy.begin(), v_copy.end());
	
	int i, j = n-1, count = 0;
	int index;
	while(1){
		while(mp[0] != 0){
			swap(vec[mp[0]], vec[mp[mp[0]]]);
			swap(mp[0], mp[mp[0]]);
			count++;
		}
		if(vec != v_copy){
			for(;j>=0 && mp[j] == j;j--);
			swap(vec[mp[0]], vec[mp[j]]);
			swap(mp[0], mp[j]);
			count++;
		}else{
			break;
		}
	}
	printf("%d", count);
}
