#include<stdio.h>
#include<string.h>

int map[1001][1001];
int visited[1001];
int need_roads[1001];

void dfs(int row, int citys){
	visited[row] = 1;
	for(int i=1;i<=citys;i++){
		if(visited[i] == 0){
			if(map[row][i] == 1){
				dfs(i, citys);
			}
		}		
	}
}

int main(){
	int citys, roads, fixs;
	int index_i, index_j;
	scanf("%d %d %d", &citys, &roads, &fixs);
	for(int i=0;i<roads;i++){
		scanf("%d %d", &index_i, &index_j);
		map[index_i][index_j] = 1;
		map[index_j][index_i] = 1;
	}
	
	int fix;
	for(int i=0;i<fixs;i++){
		memset(visited, 0, 1001*4);
		scanf("%d", &fix);
		visited[fix] = 1;
		int count = 0;
		for(int j=1;j<=citys;j++){
			if(visited[j] == 0){
				count++;
				dfs(j, citys);
			}
		}
		need_roads[i] = count - 1;
	}
	for(int i=0;i<fixs;i++){
		printf("%d\n", need_roads[i]);
	}
}
