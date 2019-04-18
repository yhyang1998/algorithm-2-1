#include <bits/stdc++.h>
#include <vector>
#define maxn 1005
#define INF 2147483647
#define PII pair<int, int>
#define f first
#define s second
using namespace std;
int n, m;
vector<PII> g[maxn];		//adjacent list
int dist[maxn];					//紀錄目前起點開始到第i個點的最近距離

void init(){
	fill(dist, dist+n+1, INF);
	dist[0] = 0;	//從0開始走
}

void bellman_ford(){
	int flag = 1;		//用來記錄有沒有人被改過
	int st, ed, w;	//start, end, weight

	for(int k = 1; k < n && flag; k++){	//跑過所有點 如果flag=0則不會繼續再做了
		flag = 0;			//預設是沒有人被改過 如果有被改到在下面會修正

		for(int i = 0; i <= n; i++){		//跑過所有邊
			for(auto k : g[i]){
				st = i, ed = k.f, w = k.s;
				if(dist[st] + w < dist[ed]){
					dist[ed] = dist[st] + w;
					flag = 1;
				}
			}
		}
	}
}

void reweight(){
	int st, ed;

	for(int i = 1; i <= n; i++){		//跑過所有邊
		for(auto k : g[i]){
			st = i, ed = k.first;
			k.second = k.second + dist[st] - dist[ed];
			printf("%d %d -> %d\n", st, ed, k.second);
		}
	}
}

int path[maxm][maxm];	//紀錄i->j的路徑長
priority_queue<PII, vector<PII>, greater<PII> > pq;	//由小到大
int choosed[maxm];		//每一個round都要重新清空一次	紀錄哪些點已經被加進正確聯盟
int dst[maxn];
//一次把所有值找好存進二維陣列
void dijkstra(){
	int fin_cnt;	//紀錄已經加進正確聯盟的點的數目
	int st, ed, w;
	priority_queue<PII, vector<PII>, greater<PII> > pq;	//由小到大
	int minn;
	int min_idx;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			path[i][j] = INF;
		}
	}
	//memset(path, 0, sizeof(path));	//全部的點都只能從自己走到

	for(int i = 1; i <= n; i++){
		memset(choosed, 0, sizeof(choosed));
		fill(dst+1, dst+n+1, INF);	//先把dst全設為INF(一開始所有點都走不到)

		dst[i] = 0;	//起點
		choosed[i] = 1;

		for(auto k : g[i]){
			st = i, ed = k.f, w = k.s;
			dst[ed] = w;	//從i出發的路徑
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
	scanf("%d %d %d", &n, &m, &q);

	//設立超級起點
	for(int i = 1; i <= n; i++){
		g[0].push_back(PII(i, 0));		//和超級起點相連的點之前的權重都是0
	}

	for(int j = 0; j < m; j++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(PII(v, w));		//建立adjacent list
	}


	init();
	bellman_ford();
	reweight();

	/*

	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(path[x][y] == INF)	printf("no path\n");
		else{
			if(x == y)	printf("0\n");
			else	printf("%d\n", path[x][y]);
		}
	}

	*/
	return 0;
}
