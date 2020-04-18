#include<cstdio>
#include<vector>

using namespace std;

#define MAXN 500
#define INF 0x3fffffff

int adj[MAXN][MAXN];
int cost[MAXN][MAXN];

bool visited[MAXN];
vector<int> path[MAXN];
int dis[MAXN]; // æ‡¿Î 

void init(int n){
	for(int i=0;i<n;i++){
		dis[i] = INF;
	}
} 

vector<int> min_path;

vector<int> temp_path;
int min_cost = INF;

void dfs(int start, int now){
	if(now == start){
		temp_path.push_back(start);
		int min = 0;
		for(int i=temp_path.size()-1;i>0;i--){
			min+=cost[temp_path[i]][temp_path[i-1]];
		}
		if(min < min_cost){
			min_cost = min;
			min_path = temp_path;
		}
		temp_path.pop_back();
		return ;
	}
	temp_path.push_back(now);
	for(int i=0;i<path[now].size();i++){
		dfs(start, path[now][i]);
	}
	temp_path.pop_back();
}

int main(){
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	init(N);
	int c1, c2, d, c;
	for(int i=0;i<M;i++){
		scanf("%d %d %d %d", &c1, &c2, &d, &c);
		adj[c1][c2] = d;
		adj[c2][c1] = d;
		cost[c1][c2] = c;
		cost[c2][c1] = c;
	}
	int start = S;
	visited[start] = true;
	dis[start] = 0;
	while(1){
		for(int i=0;i<N;i++){
			if(visited[i] == false && adj[start][i] != 0){
				if(dis[start] + adj[start][i] < dis[i]){
					dis[i] = dis[start] + adj[start][i];
					path[i].clear();
					path[i].push_back(start);
				}else if(dis[start] + adj[start][i] == dis[i]){
					path[i].push_back(start);
				}
			}
		}
		int min = INF;
		int min_index = -1;
		for(int i=0;i<N;i++){
			if(visited[i] == false){
				if(dis[i] < min){
					min = dis[i];
					min_index = i;
				}
			}
		}
		start = min_index;
		visited[start] = true;
		if(start == D){
			break;
		}
	}
	
	dfs(S, D);
	for(int i=min_path.size()-1;i>=0;i--){
		printf("%d ", min_path[i]);
	}
	printf("%d %d", dis[D], min_cost);
}
