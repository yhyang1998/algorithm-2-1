//太浪費記憶體 也很花時間
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int n;	//node數目
int tree[maxn][maxn];
int visited[maxn];		//1是走過了 0是還沒走過
int depth[maxn];

//bool cmp(int a, int b)	return a > b;
int findMax(){
	int max = 0;
	int index = 0;
	for(int i = 0; i < n; i++){
		if(depth[i] > max){
			max = depth[i];
			index = i;
			//cout << "hi!!!! ";
		}
	}
	return index;
}

void dfs(int id){
	for(int i = 0; i < n; i++){
		if(tree[id][i] == 1 && visited[i] == 0){		//可以走而且還沒被走過
			visited[i] = 1;
			depth[i] = depth[id]+1;
			dfs(i);
		}
	}
	return;
}

int main(){
	int max;
	memset(tree, 0, sizeof(tree));
	memset(visited, 0, sizeof(visited));
	memset(depth, 0, sizeof(depth));
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		tree[x][y] = 1;
		tree[y][x] = 1;
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
