#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 14:06 -  14:33
using namespace std;

struct people{
	string id;
	int virtur_grade;
	int talent_grade;
	people(string id, int virtur_grade, int talent_grade){
		this->id = id;
		this->virtur_grade = virtur_grade;
		this->talent_grade = talent_grade;
	}
};

int lower, higher;
int n;
vector<people> p1;
vector<people> p2;
vector<people> p3;
vector<people> p4;

bool cmp(people a, people b){
	if(a.talent_grade + a.virtur_grade != b.talent_grade + b.virtur_grade){
		return a.talent_grade + a.virtur_grade > b.talent_grade + b.virtur_grade;
	}
	if(a.virtur_grade != b.virtur_grade){
		return a.virtur_grade > b.virtur_grade;
	}
	return a.id < b.id;
}

void print(vector<people> p1){
	for(auto p:p1){
		printf("%s %d %d\n", p.id.data(), p.virtur_grade, p.talent_grade);
	}
}

int main(){
	scanf("%d %d %d", &n, &lower, &higher);
	char id[100];
	int g1, g2;
	for(int i=0;i<n;i++){
		scanf("%s %d %d", id, &g1, &g2);
		if(g1 >= higher && g2 >= higher){
			p1.push_back(people(id, g1, g2));
		}else if(g1 >= higher && g2 >= lower){
			p2.push_back(people(id, g1, g2));
		}else if(g1 >= g2 && g2 >= lower){
			p3.push_back(people(id, g1, g2));
		}else if(g1 >= lower && g2 >= lower){
			p4.push_back(people(id, g1, g2));
		}
	}
	sort(p1.begin(), p1.end(), cmp); 
	sort(p2.begin(), p2.end(), cmp); 
	sort(p3.begin(), p3.end(), cmp); 
	sort(p4.begin(), p4.end(), cmp); 
	printf("%d\n", p1.size() + p2.size() + p3.size() + p4.size());
	print(p1);
	print(p2);
	print(p3);
	print(p4);
}
