#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define PII pair<int, int>
#define node first
#define width second
#define maxn 10005	//	n的大小
#define INF 2147483647
using namespace std;

int n, m;
int visited[maxn], dp[maxn];	//dp裡存那個點到終點的路徑中最小的 最後要找所有dp裡最大的
vector<PII> v[maxn];

//存每個點到最後點的路徑最大值

// priority_queue<int, vector<int>, greater<int> >	q; //找一條路徑中最小的值 找完一條就清空
// priority_queue<int> w;	//存條路徑中最小的值 並且第一個會是最大的

/*
void dp(){
	for(int i = n-1; i > 0; i--){
		for(auto k : v[i]){
			if(k.node > i)	break;
			else{
				dp[k.node] = min(dp[i], k.width);
			}
		}
	}
}
*/

/*
void dfs(int id){
	for(auto k : v[id]){	//k會遍歷v[id]裡每個值

		if(visited[k.node] == 0){
			visited[k.node] = 1;
			q.push(k.width);
			//printf("%d -> ", k.node);
			if(k.node == n-1){
				w.push(q.top());
				q = priority_queue<int, vector<int>, greater<int> >();
				visited[k.node] = 0;
				break;
			}
			dfs(k.node);
			visited[k.node] = 0;
		}

	}
	return;
}
*/


int main(){
	int x, y, width, _max;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &x, &y, &width);
		//vector pair一定要一次存兩個值進去
		v[x].push_back(PII(y, width));
		v[y].push_back(PII(x, width));
	}

//	memset(visited, 0 , sizeof(visited));
	fill(dp, dp+n, INF);

	for(int i = n-1; i > 0; i--){
		for(auto k : v[i]){
			if(k.node > i)	break;
			else{
				dp[k.node] = min(dp[i], k.width);
			}
		}
	}

	sort(dp, dp+n-1, greater<int>());

//	visited[0] = 1;
//	dfs(0);
	//dfs(n-1);

	//_max = w.top();

	printf("%d\n", dp[0]);

	return 0;
}
