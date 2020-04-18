#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 14:57 -  
using namespace std;

struct people{
	string name;
	int age;
	int worth;
	people(string name, int age, int worth){
		this->name = name;
		this->age = age;
		this->worth = worth;
	}
};

int n, k;
vector<people> p[201];
vector<people> pall;

bool cmp(people a, people b){
	if(a.worth != b.worth){
		return a.worth > b.worth;
	}
	if(a.age != b.age){
		return a.age < b.age;
	}
	return a.name < b.name;
}


void print(int m, int amin, int amax, int index){
	printf("Case #%d:\n", index);
	vector<people> p2;
	int pos[201];
	fill(pos+amin, pos+amax+1, 0);
	vector<int> t1;
	for(int i=amin;i<=amax;i++){
		t1.push_back(i);
	}
	vector<int> t2;
	while(1){
		int max = 0x80000000;
		int max_index = -1;
		for(auto i:t1){
			if(p[i].size() != 0){
				if(pos[i] < p[i].size()){
					t2.push_back(i);
					if(p[i][pos[i]].worth > max){
						max = p[i][pos[i]].worth;
						max_index = i;
					}
				}
			}
		}
		if(max_index == -1){
			break;
		}else{
			p2.push_back(p[max_index][pos[max_index]]);
			pos[max_index]++;
			if(p2.size() == m){
				break;
			}
		}
		t1 = t2;
		t2.clear();
	}
	if(p2.size() == 0){
		printf("None\n");
	}else{
		for(auto r:p2){
			printf("%s %d %d\n", r.name.data(), r.age, r.worth);
		}
	}
}

int main(){
	int m, amin, amax;
	scanf("%d %d", &n, &k);
	char name[100];
	int age, worth;
	for(int i=0;i<n;i++){
		scanf("%s %d %d", name, &age, &worth);
		pall.push_back(people(name, age, worth));
	}
	sort(pall.begin(), pall.end(), cmp);
	for(int i=0;i<n;i++){
		if(p[pall[i].age].size() < 100){
			p[pall[i].age].push_back(pall[i]);
		}
	}
	for(int i=0;i<k;i++){
		scanf("%d %d %d", &m, &amin, &amax);
		print(m, amin, amax, i+1);
	}
}
