#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iostream> 

// 13:20 - 13:52
using namespace std;

int n, m;
vector<int> nc;
vector<int> np;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		nc.push_back(t);
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d", &t);
		np.push_back(t);
	}
	sort(nc.begin(), nc.end(), cmp);
	sort(np.begin(), np.end(), cmp);
	int sum = 0;
	int i = 0, j = 0;
	for(;i<nc.size() && np[j] > 0 && nc[i] >= 0;){
		sum += nc[i] * np[j];
		i++;
		j++;
	}
	if(i == nc.size()){
		printf("%d", sum);
		return 0;
	}
	j = np.size() - 1;
	i = nc.size() - 1;
	for(;i >= 0 && j >= 0 && nc[i]<0 && np[j]<0;){
		sum += nc[i] * np[j];
		i--;
		j--;
	}
	printf("%d", sum);
}
