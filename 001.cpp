#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 18:42 -  
using namespace std;

int n;

int main(){
	scanf("%d", &n);
	double sum = 0;
	for(int i=0;i<n;i++){
		double t;
		scanf("%lf", &t);
		printf("%d - %f %f\n", i, (i+1)*(n-i)*t, t*(i+1)*(n-i));
		sum += t*(i+1)*(n-i);
	}
	printf("%.2f", sum);
}
