#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

struct stu{
	string name;
	string id;
	int grade;
	stu(char name[100], char id[100], int grade){
		this->name = name;
		this->id = id;
		this->grade = grade;
	}
};

bool cmpM(stu s1, stu s2){
	return s1.grade < s2.grade;
}

bool cmpF(stu s1, stu s2){
	return s1.grade > s2.grade;
}

int n;
int main(){
	char name[50], sex[2], id[50];
	int grade;
	vector<stu> m;
	vector<stu> f;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s %s %s %d", name, sex, id, &grade);
		if(string(sex) == "M"){
			m.push_back(stu(name, id, grade));
		}else{
			f.push_back(stu(name, id, grade));
		}
	}
	sort(f.begin(), f.end(), cmpF);
	sort(m.begin(), m.end(), cmpM);
	if(f.size() == 0){
		printf("Absent\n");
		if(m.size() == 0){
			printf("Absent\n");
		}else{
			printf("%s %s\n", m[0].name.c_str(), m[0].id.c_str());
		}
		printf("NA\n");
	}else{
		printf("%s %s\n", f[0].name.c_str(), f[0].id.c_str());
		if(m.size() == 0){
			printf("Absent\n");
			printf("NA\n");
		}else{
			printf("%s %s\n", m[0].name.c_str(), m[0].id.c_str());
			printf("%d\n", f[0].grade - m[0].grade);
		}
	}
	
}
