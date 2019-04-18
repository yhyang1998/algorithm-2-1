#include <bits/stdc++.h>
#include <vector>
#define maxn 100005
using namespace std;

int n;	//node數目
vector<int> v[maxn];	//vector陣列 adjacent list
int visited[maxn];		//1是走過了 0是還沒走過
int depth[maxn];


int findMax(){
	int max = 0;
	int index = 0;
	for(int i = 0; i < n; i++){
		if(depth[i] > max){
			max = depth[i];
			index = i;
		}
	}
	return index;
}

void dfs(int id){
	/*
	for(auto k : v[id]){	//k->v[id][j](下面的)
		if(visited[k] == 0){
			visited[k] = 1;
			depth[k] = depth[id]+1;
			dfs(k);
		}
	}*/
	for(int j = 0; j < v[id].size(); j++){
		if(visited[v[id][j]] == 0){
			visited[v[id][j]] = 1;
			depth[v[id][j]] = depth[id]+1;
			dfs(v[id][j]);
		}
	}
	return;
}

int main(){
	int max;
	memset(v, 0, sizeof(v));
	memset(depth, 0, sizeof(depth));
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	visited[0] = 1;
	depth[0] = 0;

	dfs(0);
	max = findMax();
	memset(visited, 0, sizeof(visited));
	memset(depth, 0, sizeof(depth));
	dfs(max);
	max = findMax();
	printf("%d\n", depth[max]);

	return 0;
}
