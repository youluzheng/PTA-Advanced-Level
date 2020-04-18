#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 21:30-23:50
using namespace std;

struct record{
	string name;
	int month;
	int day;
	int hour;
	int min;
	string status;
};

bool cmp(record a, record b){
	if(a.name != b.name){
		return a.name < b.name;
	}
	if(a.day != b.day){
		return a.day < b.day;
	}
	if(a.hour != b.hour){
		return a.hour < b.hour;
	}
	return a.min < b.min;
}

int rate[24];
int n;
double pay_sum = 0;
int time_sum = 60*24;

double cal(record r1, record r2){
	double sum1 = 0;
	double sum2 = 0;
	
	for(int i=0;i<r1.hour;i++){
		sum1 += 60*rate[i];
	}
	sum1 += r1.min * rate[r1.hour];
	sum1 /= 100;
	
	for(int i=0;i<r2.hour;i++){
		sum2 += 60*rate[i];
	}
	sum2 += r2.min * rate[r2.hour];
	sum2 /= 100;
	
	return pay_sum*(r2.day - r1.day) - sum1 + sum2;
}

int gettime(record r1, record r2){
	int sum1 = 60*r1.hour + r1.min;
	int sum2 = 60*r2.hour + r2.min;
	return time_sum*(r2.day - r1.day) - sum1 + sum2;
}

int main(){
	vector<record> records;
	for(int i=0;i<24;i++){
		scanf("%d", &rate[i]);
		pay_sum += 60*rate[i];
	}
	pay_sum /= 100;
	
	scanf("%d", &n);
	if(n == 0){
		return 0;
	}
	
	for(int i=0;i<n;i++){
		record re;
		char name[30], status[30];
		scanf("%s %d:%d:%d:%d %s", name, &re.month, &re.day, &re.hour, &re.min, status);
		re.name = name;
		re.status = status;
		records.push_back(re);
	}
	sort(records.begin(), records.end(), cmp);
	
	int i = 0, j = 0;
	while(1){
		int flag = 0; 
		double sum = 0;
		for(j=i+1;j<records.size();j++){
			if(records[j].name != records[i].name){
				break;
			}
		}
		for(;i<j-1;i++){
			if(records[i].status == "on-line" && records[i+1].status == "off-line"){
				if(flag == 0){
					printf("%s %02d\n", records[i].name.data(), records[i].month);
					flag = 1;
				}
				record r1 = records[i];
				record r2 = records[i+1];
				printf("%02d:%02d:%02d ", r1.day, r1.hour, r1.min);				
				printf("%02d:%02d:%02d ", r2.day, r2.hour, r2.min);	
				double temp_sum = cal(r1, r2);
				sum += temp_sum;
				printf("%d $%.2f\n", gettime(r1, r2), temp_sum);
				i++;
			}
		}
		if(flag == 1){
			printf("Total amount: $%.2f\n", sum);
		}
		if(j == records.size()){
			break;
		}
		i = j;
	}
}
