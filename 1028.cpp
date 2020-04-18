#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 14:40 -  14:53
using namespace std;

struct people{
	string id;
	string name;
	int grade;
	people(string id, string name, int grade){
		this->id = id;
		this->name = name;
		this->grade = grade;
	}
};

int n, c;
vector<people> p;

bool cmp1(people a, people b){
	return a.id < b.id;
}

bool cmp2(people a, people b){
	if(a.name != b.name){
		return a.name < b.name;
	}
	return a.id < b.id;
}

bool cmp3(people a, people b){
	if(a.grade != b.grade){
		return a.grade < b.grade;
	}
	return a.id < b.id;
}

void print(vector<people> p1){
	for(auto p:p1){
		printf("%s %s %d\n", p.id.data(), p.name.data(), p.grade);
	}
}

int main(){
	scanf("%d %d", &n, &c);
	char id[100], name[100];
	int g;
	for(int i=0;i<n;i++){
		scanf("%s %s %d", id, name, &g);
		p.push_back(people(id, name, g));
	}
	if(c == 1){
		sort(p.begin(), p.end(), cmp1);
	}else if(c == 2){
		sort(p.begin(), p.end(), cmp2);
	}else{
		sort(p.begin(), p.end(), cmp3);
	}
	print(p);
}
