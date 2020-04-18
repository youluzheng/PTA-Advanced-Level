#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 17:30 -  
using namespace std;

#define MAXN 100010
#define MAXU 10010

struct u{
	int id;
	map<int, int> pro;
	int perfect;
	int sum;
	bool flag;
}user[MAXU];

int n, k, m;
int problem[MAXN];

bool cmp(u a, u b){
	if(a.flag != b.flag){
		return a.flag > b.flag;
	}
	if(a.sum != b.sum){
		return a.sum > b.sum;
	}
	if(a.perfect != b.perfect){
		return a.perfect > b.perfect; 
	}
	return a.id < b.id;
}

int main(){
	scanf("%d %d %d", &n, &k, &m);
	for(int i=1;i<=k;i++){
		scanf("%d", &problem[i]);
	}
	int id, pro, score;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &id, &pro, &score);
		user[id].id = id;
		if(score >= 0){
			user[id].flag = true;
		}
		if(score == -1){
			if(user[id].pro.count(pro) == 0){
				user[id].pro[pro] = 0;
			}
		}else if(score >= 0){
			if(user[id].pro.count(pro) == 0){
				user[id].pro[pro] = score;
				if(score == problem[pro]){
					user[id].perfect++;
				}
				user[id].sum += score;
			}else if(user[id].pro[pro] < score){
				user[id].sum -= user[id].pro[pro];
				user[id].pro[pro] = score;
				user[id].sum += score;
				if(score == problem[pro]){
					user[id].perfect++;
				}
			}
		}
	}
	sort(user, user+MAXU, cmp);
//	for(int i=0;i<20;i++){
//		printf("%d %d %d %d\n", user[i].id, user[i].sum, user[i].perfect, user[i].flag);
//		for(auto b:user[i].pro){
//			printf("  %d %d\n", b.first, b.second);
//		}
//	}
	int rank = 1;
	int sum = user[0].sum;
	for(int i=0;user[i].flag != false;i++){
		if(user[i].sum != sum){
			rank = i+1;
			sum = user[i].sum;
		}
		printf("%d %05d %d ", rank, user[i].id, user[i].sum);
		for(int j=1;j<k;j++){
			if(user[i].pro.count(j) == 0){
				printf("- ");
			}else{
				printf("%d ", user[i].pro[j]);
			}
		}
		if(user[i].pro.count(j) == 0){
			printf("- ");
		}else{
			printf("%d ", user[i].pro[j]);
		}
		printf("\n");
	}
}
