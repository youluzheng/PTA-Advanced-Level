#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 19:15 -  19:28
using namespace std;

int all[128];
int need[128];

int main(){
	fill(all, all+128, 0);
	fill(need, need+128, 0);
	char s1[1001];
	char s2[1001];
	scanf("%s %s", s1, s2);
	for(int i=0;s1[i]!='\0';i++){
		all[s1[i]]++; 
	}
	for(int i=0;s2[i]!='\0';i++){
		need[s2[i]]++; 
	}
	int count1 = 0;
	int count2 = 0;
	for(int i=0;i<128;i++){
		if(all[i] > need[i]){
			count1 += all[i] - need[i];
		}else if(all[i] < need[i]){
			count2 += need[i] - all[i];
		}
	}
	if(count2 == 0){
		printf("Yes %d", count1);
	}else{
		printf("No %d", count2);
	}
}
