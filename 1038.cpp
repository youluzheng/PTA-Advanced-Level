#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 14:50 - 15:51 
using namespace std;


int n;
vector<string> s;

bool cmp(string a, string b){
	return a+b < b+a;
}

string deal(string a){
	for(int i=0;i<a.length();i++){
		if(a[i] != '0'){
			return a.data()+i;
		}
	}
	return "";
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		char str[100];
		scanf("%s", str);
		s.push_back(str);
	}
	sort(s.begin(), s.end(), cmp);
	int i = 0;
	for(i=0;i<n && (s[i] = deal(s[i])) == "";i++);
	if(i == n){
		printf("0");
	}else{
		for(i=0;i<s.size();i++){
			printf("%s", s[i].data());
		}
	}
}
