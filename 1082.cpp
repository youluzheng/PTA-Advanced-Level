#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iostream> 

// 14:46-15:54
using namespace std;

string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int n;

void dg(int num, int level, bool pre){
	int f = num/(int)pow(10, level);
	int e = num%(int)pow(10, level);
	if(f == 0){
		if(pre){
			printf("ling ");
		}
		dg(e, level-1, false);
	}else{
		printf("%s", digit[f].data());
		if(e == 0){
			if(level == 8){
				printf(" Yi");
			}else if(level == 7){
				printf(" Qian Wan");
			}else if(level == 6){
				printf(" Bai Wan");
			}else if(level == 5){
				printf(" Shi Wan");
			}else if(level == 4){
				printf(" Wan");
			}else if(level == 3){
				printf(" Qian");
			}else if(level == 2){
				printf(" Bai");
			}else if(level == 1){
				printf(" Shi");
			}
		}else{
			if(level == 8){
				printf(" Yi ");
			}else if(level == 7){
				printf(" Qian ");
				if(e < pow(10, 4)){
					printf("Wan ");
				}
			}else if(level == 6){
				printf(" Bai ");
				if(e < pow(10, 4)){
					printf("Wan ");
				}
			}else if(level == 5){
				printf(" Shi ");
				if(e < pow(10, 4)){
					printf("Wan ");
				}
			}else if(level == 4){
				printf(" Wan ");
			}else if(level == 3){
				printf(" Qian ");
			}else if(level == 2){
				printf(" Bai ");
			}else if(level == 1){
				printf(" Shi ");
			}
			if(level < 8 && level > 4 && e < pow(10, 4)){
				dg(e, 3, true);
			}else{
				dg(e, level-1, true);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	if(n < 0){
		printf("Fu ");
		n = -n;
	}
	if(n == 0){
		printf("ling");
	}else{
		dg(n, 8, false);
	}
}
