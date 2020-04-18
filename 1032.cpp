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
#define debug printf("-catch-\n");

void show(map<string, string> s){
	for(map<string, string>::iterator it=s.begin();it!=s.end();it++){
		printf("%s %s\n", it->first.c_str(), it->second.c_str());
	}
}

void toString() {
	
}

bool cmp(char a, char b) {
	return a>b;
}

struct student{
	string name;
	int score;
	friend bool operator < (student s1, student s2){
		return s1.score > s2.score;
	}
	student(string _name, int _score){
		name = _name;
		score = _score;
	}
};

void print(student s1, string name){
	printf("%s -> [name: %s, score: %d]\n", name.c_str(), s1.name.c_str(), s1.score);	
}


int main() {
	int n;
	string a, b;
	cin>>a>>b>>n;
	map<string, string> common;
	set<string> c1;
	for(int i=0;i<n;i++){
		string s1, s2;
		char ch;
		cin>>s1>>ch>>s2;
		common[s1] = s2;
	}
	string _a = a;
	c1.insert(_a);
	while((_a = common[_a]) != "-1"){
		c1.insert(_a);
	}
	c1.insert(_a);
	
	string _b = b;
	if(c1.find(_b) != c1.end()){
		printf("%s", _b.c_str());
		return 0;
	}
	while((_b = common[_b]) != "-1"){
		if(c1.find(_b) != c1.end()){
			printf("%s", _b.c_str());
			return 0;
		}
	}
	printf("-1");
}
