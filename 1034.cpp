#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

map<string, string> father;
map<string, int> weights;
map<string, int> sum;

string findfather(string x){
	if(father[x] == ""){
		father[x] = x;
	}else{
		while(father[x] != x){
			x = father[x];
		}
	}
	return x;
}

bool cmp(string s1, string s2){
	return weights[s1] > weights[s2];
}

void collect(int k){
	vector<string> res;
	map<string, set<string> > col;
	for(auto a:father){
		col[findfather(a.first)].insert(a.first);
	}
	for(auto a:col){
		if(a.second.size() > 2 && sum[findfather(a.first)] > k){
			vector<string> temp(a.second.begin(), a.second.end());
			sort(temp.begin(), temp.end(), cmp);
			res.push_back(temp[0]);		
		}
	}
	sort(res.begin(), res.end(), [](string s1, string s2){
		return s1 < s2;
	});
	printf("%d\n", res.size());
	for(auto a:res){
		printf("%s %d\n", a.c_str(), col[findfather(a)].size());
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	char n1[10], n2[10];
	int w;
	for(int i=0;i<n;i++){
		scanf("%s %s %d", n1, n2, &w);
		weights[n1] += w;
		weights[n2] += w;
		string f1 = findfather(n1);
		string f2 = findfather(n2);
		if(f1 != f2){
			sum[f1] += sum[f2];
			father[f2] = f1;
		}
		sum[f1] += w; 
	}
	collect(k);
}
