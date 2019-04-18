#include <bits/stdc++.h>
#define maxn 6005		//m+n
#define maxm 1005
#define INF 2147483647
#define PII pair<int, int>
#define f first
#define s second
using namespace std;
int n, m;
int dist[maxm];		//紀錄目前起點開始到第i個點的最近距離
pair<int, PII> node[maxn];		//第一個存w 第二個存起、終點

void init(){
	for(int i = 0; i <= n; i++){
		dist[i] = INF;
	}
	dist[0] = 0;	//從0開始走
}

void bellman_ford(){
	int flag = 1;		//用來記錄有沒有人被改過
	int st, ed, w;	//start, end, weight

	for(int k = 1; k < n && flag; k++){	//跑過所有點 如果flag=0則不會繼續再做了
		flag = 0;			//預設是沒有人被改過 如果有被改到在下面會修正
		for(int i = 0; i < n+m; i++){		//跑過所有的邊
			st = node[i].s.f;
			ed = node[i].s.s;
			w = node[i].f;
			//先看st -> ed
			if(dist[st] + w < dist[ed]){
				dist[ed] = dist[st] + w;
				flag = 1;

			}
			//再看ed -> st
			/*
			if(dist[ed] + w < dist[st]){
				dist[st] = dist[ed] + w;
				flag = 1;
				//printf("b %d %d %d dist[%d] = %d\n", st, ed, w, st, dist[st]);
			}*/
		}

	}
}

void reweight(){
	int st, ed;

	for(int i = n; i < n+m; i++){
		st = node[i].s.f;
		ed = node[i].s.s;
		node[i].f = node[i].f + dist[st] - dist[ed];
		//printf("%d %d -> %d\n", st, ed, node[i].f);
	}

}

int path[maxm][maxm];	//紀錄i->j的路徑長
int choosed[maxm];		//每一個round都要重新清空一次	紀錄哪些點已經被加進正確聯盟
int dst[maxn];
//一次把所有值找好存進二維陣列
void dijkstra(){
	int fin_cnt;	//紀錄已經加進正確聯盟的點的數目
	int st, ed, w;
	int minn;
	int min_idx;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			path[i][j] = INF;
		}
	}
	memset(path, 0, sizeof(path));	//全部的點都只能從自己走到

	for(int i = 1; i <= n; i++){
		memset(choosed, 0, sizeof(choosed));
		fill(dst+1, dst+n+1, INF);	//先把dst全設為INF(一開始所有點都走不到)

		dst[i] = 0;	//起點
		choosed[i] = 1;

		for(int j = n; j < n+m; j++){
			st = node[j].s.f;
			ed = node[j].s.s;
			w = node[j].f;
			if(st == i)	dst[ed] = w;		//從i出發的路徑
		}

		/*
		for(int j = 1; j <= n; j++)	printf("dst[%d] = %d ", j, dst[j]);
		printf("\n");
		*/
		fin_cnt = 1;	//起點被加進正確聯盟

		//針對起點i做走到每一點的最小路徑更新
		while(fin_cnt < n){
			minn = INF;
			min_idx = -1;

			//跑過所有點找最小值
			for(int k = 1; k <= n; k++){
				if(choosed[k] == 1)	continue;	//如果已經在正確聯盟裡就跳過
				if(dst[k] < minn){
					min_idx = k;
					minn = dst[k];
				}
			}

			if(min_idx == -1)	break;	//如果沒找到代表這個圖找不到下一個可以更新的點
			choosed[min_idx] = 1;
			path[i][min_idx] = minn + dist[min_idx] - dist[i];	//最終的路徑長！！
			//printf("path[%d][%d] = %d ", i, min_idx, path[i][min_idx]);
			fin_cnt++;

			//看看還沒被選的點有沒有可以透過min_idx更新而更小的點
			for(int j = n; j < n+m; j++){
				st = node[j].s.f;
				ed = node[j].s.s;
				w = node[j].f;
				if(st == min_idx){
					if(dst[min_idx] + w < dst[ed]){
						dst[ed] = dst[min_idx] + w;
					}
				}
			}
		}
		//printf("\n");

	}

}

int main(){
	int q;
	scanf("%d%d%d", &n, &m, &q);
	//設立超級起點
	for(int i = 0; i < n; i++){
		node[i].f = 0;
		node[i].s.f = 0;
		node[i].s.s = i+1;
	}
	for(int i = n; i < n+m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		node[i].f = w;
		node[i].s.f = u;
		node[i].s.s = v;
	}

	init();
	bellman_ford();
	reweight();
	dijkstra();

	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(path[x][y] == INF)	printf("no path\n");
		else{
			if(x == y)	printf("0\n");
			else	printf("%d\n", path[x][y]);
		}	
	}

	return 0;
}
