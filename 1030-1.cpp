#include<cstdio>
#include<vector>

using namespace std;

#define MAXN 500
#define INF 0x3fffffff

int adj[MAXN][MAXN];
int cost[MAXN][MAXN];

bool visited[MAXN];
int path[MAXN];
int dis[MAXN]; // æ‡¿Î 
int cos[MAXN]; // ª®∑—

void init(int n){
	for(int i=0;i<n;i++){
		dis[i] = INF;
		cos[i] = INF;
	}
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
	path[start] = start;
	dis[start] = 0;
	cos[start] = 0;
	while(1){
		for(int i=0;i<N;i++){
			if(visited[i] == false && adj[start][i] != 0){
				if(dis[start] + adj[start][i] < dis[i]){
					dis[i] = dis[start] + adj[start][i];
					cos[i] = cos[start] + cost[start][i];
					path[i] = start;
				}else if(dis[start] + adj[start][i] == dis[i] && cos[start] + cost[start][i] < cos[i]){
					dis[i] = dis[start] + adj[start][i];
					cos[i] = cos[start] + cost[start][i];
					path[i] = start;
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
	int end = D;
	vector<int> way;
	way.push_back(D);
	while(D != path[D]){
		D = path[D];
		way.push_back(D);
	}
	for(int i=way.size()-1;i>=0;i--){
		printf("%d ", way[i]);
	}
	printf("%d %d", dis[end], cos[end]);
}
