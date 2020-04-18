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
	string weight;
	vector<int> children;
}nodes[101];

string add(string s1, string s2){
	char a, b;
	if(s1.length() > s2.length()){
		s2.resize(s1.length(), '0');
	}else{
		s1.resize(s2.length(), '0');
	}
	int c = 0;
	string result = "";
	int i = 0;
	for(i=0;i<s1.length();i++){
		a = s1[i]-'0';
		b = s2[i]-'0';
		char res = a+b+c;
		c = res>9?1:0;
		result += res%10+'0';	
	}
	if(c == 1){
		result+=1+'0';
	}
	return result;
}

int compare(string s1, string s2){
	if(s1.length() != s2.length()){
		return s1.length() - s2.length();
	}
	string _s1 = s1, _s2 = s2;
	reverse(_s1.begin(), _s1.end()); 
	reverse(_s2.begin(), _s2.end()); 
	if(_s1 > _s2){
		return 1;
	}else if(s1 == s2){
		return 0;
	}else{
		return -1;
	}
}

bool cmp(int a, int b) {
	int res = compare(nodes[a].weight, nodes[b].weight);
	return res>0?true:false;
}

void pre(int index, string result, string sum, string weight_sum){
	sum = add(sum, nodes[index].weight);
	string str = nodes[index].weight;
	reverse(str.begin(), str.end());
	int res = compare(sum, weight_sum);
	if(res > 0 ){
		return ;
	}
	if(res == 0){
		if(nodes[index].children.size() == 0){
			result += str;
			printf("%s\n", result.c_str());
		}
		return ;
	}
	if(res < 0){
		if(nodes[index].children.size() == 0){
			return ;
		}
		result += str + " ";
		for(int i=0;i<nodes[index].children.size();i++){
			pre(nodes[index].children[i], result, sum, weight_sum);
		}
	}
}

int main() {
	int N, M;
	char S[31];
	scanf("%d %d %s", &N, &M, S);
	string weight_sum = S;
	reverse(weight_sum.begin(), weight_sum.end());   
	vector<string> weights;  
	if(N == 0){
		return 0;
	}                   
	for(int i=0;i<N;i++){
		scanf("%s", S);
		string weight = S;
		reverse(weight.begin(), weight.end());
		weights.push_back(weight);
	}
	
	int parent, kid_num;
	for(int i=0;i<M;i++){
		scanf("%d %d", &parent, &kid_num);
		int name;
		for(int j=0;j<kid_num;j++){
			scanf("%d", &name);
			nodes[parent].children.push_back(name); 
			nodes[name].weight = weights[name];
		}
		sort(nodes[parent].children.begin(), nodes[parent].children.end(), cmp);
	}
	nodes[0].weight = weights[0];
	
	pre(0, "", "0", weight_sum);
}
