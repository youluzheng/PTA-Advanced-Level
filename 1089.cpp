#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 15:06 -  16:29
using namespace std;

int n;

int judge(vector<int>& seq1){
	int m = 2;
	while(1){
		int i = 0, j = 0;
		for(i=j;j<n;i=j){
			j = i+m;
			if(j > n){
				j = n;
			}
			for(;i<j-1;i++){
				if(seq1[i] > seq1[i+1]){
					return m/2;
					break;
				}
			}
		}
		if(m*2 > n){
			return m;
		}
		m *= 2;
	}
		
}

void mysort(vector<int>& seq, int m){
	int i = 0, j = 0;
	for(;j<n;i=j){
		j = i + m;
		if(j > n){
			j = n;
		}
		sort(seq.begin()+i, seq.begin()+j);
	}
} 

int main(){
	scanf("%d", &n);
	vector<int> seq;
	vector<int> seq1;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		seq.push_back(t);
	}
	for(int i=0;i<n;i++){
		int t;
		scanf("%d", &t);
		seq1.push_back(t); 
	}

	int i = 0, j = 0;
	int t = judge(seq1);
	if(t  == 1){
		printf("Insertion Sort\n");
		for(;i<n-1;i++){
			if(seq1[i] > seq1[i+1]){
				j = i+1;
				break;
			}
		}
		for(i=j-1;i>=0;i--){
			if(seq1[i]<seq1[j]){
				break;
			}
		}
		int temp = seq1[j];
		seq1.erase(seq1.begin()+j);
		seq1.insert(seq1.begin()+i+1, temp);
	}else{
		printf("Merge Sort\n");
		if(t*2 >= n){
			sort(seq1.begin(), seq1.end());
		}else{
			mysort(seq1, t*2);
		}
	}
	for(j=0;j<n-1;j++){
		printf("%d ", seq1[j]);
	}
	printf("%d", seq1[j]);
}
