#include<cstdio>
#include<vector>
#include<string>

using namespace std;

#define MAXN 100001
#define INF 0x3fffffff

int t;
long long a, b, c;

long long A[11];
long long B[11];
long long C[11];

int main(){
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
	}
	for(int i=1;i<=t;i++){
		if(A[i] > 0 && B[i] > 0 && A[i] + B[i] <= 0){
			printf("Case #%d: true\n", i);
		}else if(A[i] < 0 && B[i] < 0 && A[i] + B[i] >= 0){
			printf("Case #%d: false\n", i);
		}else{
			if(A[i] + B[i] > C[i]){
				printf("Case #%d: true\n", i);
			}else{
				printf("Case #%d: false\n", i);
			}
		}
	}
}
