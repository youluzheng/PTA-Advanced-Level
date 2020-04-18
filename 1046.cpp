#include<cstdio>
#include<vector>
#include<string>

using namespace std;

#define MAXN 100001
#define INF 0x3fffffff

int cicle[MAXN];
int n, m; 
int sum;

int getsum(int n1, int n2){
	int res = 0;
	for(int i=n1;i<n2;i++){
		res += cicle[i];
	}
	return res < sum/2?res:sum-res;
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &cicle[i]);
		sum += cicle[i];
	}
	scanf("%d", &m);
	int n1, n2;
	for(int i=0;i<m;i++){
		scanf("%d %d", &n1, &n2);
		if(n1 > n2){
			printf("%d\n", getsum(n2, n1));
		}else{
			printf("%d\n", getsum(n1, n2));
		}
	}
}
