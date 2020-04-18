#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 100000

void showD1(int a[], int size){
	printf("----\n");
	for(int i=0;i<size;i++){
		printf("%d ", a[i]);
	}
	printf("----\n");
}


bool cmp(char a, char b){
	return a>b;
}

struct fra{
	int x;
	int n;
}f[10]; 

void show(fra a[], int size, int x){
	printf("%d=", x);
	int i = 0;
	for(i=0;i<size-1;i++){
		if(a[i].n == 1){
			printf("%d*", a[i].x);
		}else{
			printf("%d^%d*", a[i].x, a[i].n);
		}
	}
	if(a[i].n == 1){
		printf("%d", a[i].x);
	}else{
		printf("%d^%d", a[i].x, a[i].n);
	}
}

bool isPrime[MAXN];
int prime[MAXN];

void init(){
	int count = 0;
	for(int i=2;i<=MAXN;i++){
		if(isPrime[i] == false){
			prime[count++] = i;
			for(int j=i+i;j<MAXN;j+=i){
				isPrime[j] = true;
			}
		}
	}
}


int main(){
	int x;
	init();
	scanf("%d", &x); 
	int x_copy = x;
	if(x == 1){
		printf("1=1");
		return 0;
	} 
	int count = 0;
	int sqr = sqrt(x);
	for(int i=0;i<sqr;i++){
		if(x % prime[i] == 0){
			f[count].x = prime[i];
			f[count].n = 1;
			x/=prime[i];
			while(x % prime[i] == 0){
				f[count].n++;
				x/=prime[i];
			}
			count++;
		}
		if(x == 1){
			break;
		} 
	}
	if(x != 1){
		f[count].x = x;
		f[count].n = 1;
		count++;
	}
	show(f, count, x_copy);
	return 0;
} 
