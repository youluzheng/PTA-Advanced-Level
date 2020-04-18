#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 23:17 - 1:03
using namespace std;

struct car{
	string name;
	int hh;
	int mm;
	int ss;
	string status;
	car(char* name, int hh, int mm, int ss, char* status){
		this->name = name;
		this->hh = hh;
		this->mm = mm;
		this->ss = ss;
		this->status = status;
	}
};

int n, k;
vector<car> cars;
vector<car> car2;
map<string, int> alltime; 

int caldiff(car a, car b){
	int time1 = a.hh * 60 * 60 + a.mm * 60 + a.ss;
	int time2 = b.hh * 60 * 60 + b.mm * 60 + b.ss;
	return time1>time2?time1-time2:time2-time1;
}

string timetostring(int time){
	int hh = time/3600;
	int mm = time%3600/60;
	int ss = time%60;
	char str[20];
	sprintf(str, "%02d:%02d:%02d", hh, mm, ss);
	return str;
}

bool cmp(car a, car b){
	if(a.name != b.name){
		return a.name < b.name; 
	}
	if(a.hh != b.hh){
		return a.hh < b.hh;
	}
	if(a.mm != b.mm){
		return a.mm < b.mm;
	}
	return a.ss < b.ss;
}

bool cmp2(car a, car b){
	if(a.hh != b.hh){
		return a.hh < b.hh;
	}
	if(a.mm != b.mm){
		return a.mm < b.mm;
	}
	return a.ss < b.ss;
}

string gettime(car a){
	char str[20];
	sprintf(str, "%02d:%02d:%02d", a.hh, a.mm, a.ss);
	return str;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		char name[100], status[10];
		int hh, mm, ss;
		scanf("%s %d:%d:%d %s", name, &hh, &mm, &ss, status);
		cars.push_back(car(name ,hh ,mm, ss, status));
	}
	sort(cars.begin(), cars.end(), cmp); 
	
	// 获得有效数据，存入car2 
	int i = 0, j = 0;
	while(1){
		for(i=j,j++;j<n;j++){
			if(cars[j].name != cars[j-1].name){
				break;
			}
		}
		for(;i<j-1;i++){
			if(cars[i].status == "in" && cars[i+1].status == "out"){
				car2.push_back(cars[i]);
				car2.push_back(cars[i+1]);
				i++;
			}
		}
		if(j == n){
			break;
		}
	}
	
	// 计算没辆车的停车时间s 
	for(i=0;i<car2.size()-1;i+=2){
		alltime[car2[i].name] += caldiff(car2[i], car2[i+1]);
	}
	
	// 按照时间排序 
	sort(car2.begin(), car2.end(), cmp2);
	
	// 计算每个时间点的车数 
	int count = 0;
	map<string, int> time_;
	for(auto a:car2){
		if(a.status == "in"){
			count++;
			time_[gettime(a)] = count;
		}else{
			count--;
			time_[gettime(a)] = count;
		}
	}

	// 输出车数 
	auto it = time_.begin();
	for(i=0;i<k;i++){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		char sss[20];
		sprintf(sss, "%02d:%02d:%02d", hh, mm, ss);
		string str = sss;
		
		for(;it!=time_.end() && str>=it->first;it++);
		
		if(it == time_.begin()){
			printf("0\n");
		}else{
			advance(it, -1);
			printf("%d\n", it->second);
		}
	}
	
	// 获得最大时间的车 
	int maxtime = -1;
	for(auto a:alltime){
		if(a.second > maxtime){
			maxtime = a.second;
		}
	}
	vector<string> maxname;
	for(auto a:alltime){
		if(a.second == maxtime){
			maxname.push_back(a.first);
		}
	}
	
	// 按名字排序 
	sort(maxname.begin(), maxname.end(), [](string a, string b){
		return a<b;
	});
	
	// 输出 
	for(auto a:maxname){
		printf("%s ", a.data());
	}
	printf("%s", timetostring(maxtime).data());
}
