#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 13:28-14:20
using namespace std;

#define MAXN 101

int n;
string s[MAXN];

string same(string end, string s2){
	if(end.length() > s2.length()){
		swap(end, s2);
	}
	for(int i=end.length();i>0;i--){
		if(s2.substr(s2.length()-i, i) == end.substr(end.length()-i, i)){
			return end.substr(end.length()-i, i);
		}
	}
	return "";
}

int main(){
	scanf("%d", &n);
	getchar();
	string temp;
	for(int i=0;i<n;i++){
		getline(cin, temp);
		s[i] = temp;
	}
	string end = s[0];
	for(int i=1;i<n;i++){
		end = same(end, s[i]);
		if(end.length() == 0){
			printf("nai");
			return 0;
		}
	}
	printf("%s", end.data());
}
