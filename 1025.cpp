#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct stu{
	int location_number;
	char registration_number[14];
	int score;
	int local_rank;
	int final_rank;
};

int cmp(stu a, stu b){
	if(a.score == b.score){
		return strcmp(a.registration_number, b.registration_number)<0;
	}
	return a.score>b.score; 
}

void show(stu s[], int size){
	printf("----\n");
	for(int i=0;i<size;i++){
		printf("%s %d %d %d\n", 
		s[i].registration_number, s[i].score, 
		s[i].location_number, s[i].local_rank);
	}
	printf("----\n");
}

void _show(stu s[], int size){
	for(int i=0;i<size;i++){
		printf("%s %d %d %d\n", 
		s[i].registration_number, s[i].final_rank, 
		s[i].location_number, s[i].local_rank);
	}
}

void showD1(int a[], int size){
	printf("----\n");
	for(int i=0;i<size;i++){
		printf("%d ", a[i]);
	}
	printf("----\n");
}

void localRank(stu s[], int size){
	sort(s, s+size, cmp);
	int local_rank = 1;
	s[0].local_rank = local_rank;
	for(int i=1;i<size;i++){
		if(s[i].score != s[i-1].score){
			local_rank = i+1;
		}
		s[i].local_rank = local_rank;
	}
}

void finalRank(stu s[], int size){
	sort(s, s+size, cmp);
	int final_rank = 1;
	s[0].final_rank = final_rank;
	for(int i=1;i<size;i++){
		if(s[i].score != s[i-1].score){
			final_rank = i+1;
		}
		s[i].final_rank = final_rank;
	}
}

void stucat(stu s[], stu s1[], int start, int length){
	for(int i=0;i<length;i++){
		s[start+i] = s1[i];
	}
}

int main(){
	stu s[30000];
	int N;
	scanf("%d", &N);
	
	int num = 0;
	for(int i=0;i<N;i++){
		int K;
		scanf("%d", &K);
		stu s1[K];
		for(int j=0;j<K;j++){
			scanf("%s %d", s1[j].registration_number, &s1[j].score);
			s1[j].location_number = i+1;
		}
		localRank(s1, K);
		stucat(s, s1, num, K);
		num += K;
	}
	finalRank(s, num);
	printf("%d\n", num);
	_show(s, num);
	return 0;
} 
