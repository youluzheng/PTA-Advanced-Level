#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 19:43 - 19:49
using namespace std;

int main(){
	string s1, s2;
	map<char, int> mp;
	getline(cin, s1, '\n');
	getline(cin, s2, '\n');
	for(int i=0;i<s2.length();i++){
		mp[s2[i]]++;
	}
	for(int i=0;i<s1.length();i++){
		if(mp[s1[i]] == 0){
			printf("%c", s1[i]);
		}
	}
}
