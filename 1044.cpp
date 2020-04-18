#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 22:00 - 23:34
using namespace std;

int n, p;

int main(){
	scanf("%d %d", &n, &p);
	int seq[n];
	for(int i=0;i<n;i++){
		scanf("%d", &seq[i]);
	}
	int min_value = 0x7fffffff;
	vector<string> res;
	
	int i = 0, j = 0;
	int sum = 0;
	
	while(j<n){
		for(;j<n;j++){
			sum += seq[j];
			if(sum >= p){
				if(min_value > sum){
					min_value = sum;
					res.clear();
					res.push_back(to_string(i+1) + "-" + to_string(j+1));
				}else if(min_value == sum){
					res.push_back(to_string(i+1) + "-" + to_string(j+1));
				}
				break;
			}
		}
		if(j == n){
			break;
		}
		for(;i<=j;){
			sum -= seq[i];
			i++;
			if(sum >= p){
				if(min_value > sum){
					min_value = sum;
					res.clear();
					res.push_back(to_string(i+1) + "-" + to_string(j+1));
				}else if(min_value == sum){
					res.push_back(to_string(i+1) + "-" + to_string(j+1));
				}
			}else{
				break;
			}
		}
		j++;
	}
	for(auto a:res){
		printf("%s\n", a.data());
	}
}
