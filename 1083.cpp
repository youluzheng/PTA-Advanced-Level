#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 21:39 -  21:50
using namespace std;

struct stu{
	string name;
	string id;
	int grade;
	bool flag;
	stu(string name, string id, int grade){
		this->name = name;
		this->id = id;
		this->grade = grade;
	}
};

int n, g1, g2;
vector<stu> students;

bool cmp(stu a, stu b){
	if(a.flag != b.flag){
		return a.flag > b.flag;
	}
	return a.grade > b.grade;
}

int main(){
	scanf("%d", &n);
	char name[50], id[50];
	int grade;
	for(int i=1;i<=n;i++){
		scanf("%s %s %d", name, id, &grade);
		students.push_back(stu(name, id, grade));
	}
	scanf("%d %d", &g1, &g2);
	for(int i=0;i<n;i++){
		if(students[i].grade >= g1 && students[i].grade <= g2){
			students[i].flag = true;
		}
	}
	sort(students.begin(), students.end(), cmp);
	if(students[0].flag == false){
		printf("NONE");
	}else{
		for(int i=0;students[i].flag != false;i++){
			printf("%s %s\n", students[i].name.data(), students[i].id.data());
		}
	}
}
