#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<iostream> 

// 21:50 - 23:10
using namespace std;

struct stu{
	int id;
	double g1;
	double g2;
	double g3;
	int choices[5];
	int rank;
}s[40001];

int n, m, k;
vector<int> school[101];
int cap[101];

bool cmp(stu a, stu b){
	if(a.g3 != b.g3){
		return a.g3 > b.g3;
	}
	return a.g1 > b.g1;
}

void choiceschool(int i, int j){
	int pos[n];
	fill(pos, pos+n, 0);
	for(int k2=i;k2<j;k2++){
		if(pos[k2] != -1){
			int sid = s[k2].choices[pos[k2]];
			if(school[sid].size() < cap[sid]){
				pos[k2] = -1;
				school[sid].push_back(s[k2].id);
				for(int k1=k2+1;k1<j;k1++){
					while(1){
						if(s[k1].choices[pos[k1]] == sid){
							pos[k1] = -1;
							school[sid].push_back(s[k1].id);
							break;
						}else if(school[s[k1].choices[pos[k1]]].size() >= cap[s[k1].choices[pos[k1]]]){
							pos[k1]++;
							if(pos[k1] >= k){
								pos[k1] = -1;
								break;
							}
						}else{
							break;
						}
					}
				}
			}else{
				pos[k2]++;
				if(pos[k2] < k){
					k2--;
				}
				continue;
			}
		}
	}
}

void print(){
	for(int i=0;i<m;i++){
		if(school[i].size() != 0){
			sort(school[i].begin(), school[i].end());
			for(int j=0;j<school[i].size()-1;j++){
				printf("%d ", school[i][j]);
			}
			printf("%d\n", school[i][school[i].size()-1]);
		}else{
			printf("\n");
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<m;i++){
		scanf("%d", &cap[i]);
	}
	for(int i=0;i<n;i++){
		s[i].id = i;
		scanf("%lf %lf", &s[i].g1, &s[i].g2);
		s[i].g3 = (s[i].g1 + s[i].g2)/2;
		for(int j=0;j<k;j++){
			scanf("%d", &s[i].choices[j]);
		}
	}
	sort(s, s+n, cmp);
	int rank = 1;
	double g1 = s[0].g1, g3 = s[0].g3;
	for(int i=0;i<n;i++){
		if(s[i].g3 != g3 || (s[i].g3 == g3 && s[i].g1 != g1)){
			rank = i+1;
			g3 = s[i].g3;
			g1 = s[i].g1;
		}
		s[i].rank = rank;
	}
	int i = 0, j = 0;
	while(1){
		for(i=j,j++;j<n;j++){
			if(s[j].rank != s[j-1].rank){
				break;
			}
		}
		choiceschool(i, j);
		if(j == n){
			break;
		}
	}
	print();
}
