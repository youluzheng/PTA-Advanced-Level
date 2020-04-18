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

struct node{
	string add;
	int score;
	node(string _add, int _score){
		add = _add;
		score = _score;
	}
};

bool cmp(node a, node b) {
	return a.score < b.score;
}

void show(map<string, pair<string, int> > s){
	printf("---show---\n");
	for(map<string, pair<string, int> >::iterator it=s.begin();it!=s.end();it++){
		printf("%s %d %s\n", it->first.c_str(), it->second.second, it->second.first.c_str());
	}
	printf("---show end---\n");
}

void show1(vector<node> s){
	printf("---show1---\n");
	for(vector<node>::iterator it=s.begin();it!=s.end();it++){
		printf("%s %d\n", it->add.c_str(), it->score);
	}
	printf("---show1 end---\n");
}


void toString() {
	
}

void print(vector<node> s){
	int i=0;
	for(i=0;i<s.size()-1;i++){
		printf("%s %d %s\n", s[i].add.c_str(), s[i].score, s[i+1].add.c_str());
	}
	printf("%s %d -1", s[i].add.c_str(), s[i].score);
}


int main() {
	vector<node> list;
	map<string, pair<string, int> > mp;
	int n;
	char start[10];
	scanf("%d %s", &n, start);
	for(int i=0;i<n;i++){
		char a[10], b[10];
		int num;
		scanf("%s %d %s", a, &num, b);
		mp[string(a)] = make_pair(string(b), num);
	}
	string _start = start;
	if(_start == "-1"){
		printf("0 -1");
		return 0;
	}
	while(_start != "-1"){
		pair<string, int> p = mp[_start];
		list.push_back(node(_start, p.second));
		_start = p.first;
	}
	sort(list.begin(), list.end(), cmp);
	printf("%d %s\n", list.size(), list[0].add.c_str());
	print(list);
}
