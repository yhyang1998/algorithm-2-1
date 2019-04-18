#include <bits/stdc++.h>
#include <vector>
#define maxn 100005
using namespace std;

vector<int> v[maxn];
//int dis[maxn]	//紀錄從root走到那個點有多長
int visited[maxn];	//紀錄那個點走過了沒 0->還沒 1->	走過了

int far_index;
int max_cnt = 0;	//目前root找到最遠的距離
void dfs(int n, int cnt){		//cnt是這個點目前離跟節點多遠
	visited[n] = 1, cnt++;	//先++是先假設這個點連到得點還沒被走過
	for(auto k : v[n]){
		if(!visited[k]){ //k還沒被走過
			if(cnt >= max_cnt){	//找到更遠的了
				far_index = k;
				max_cnt = cnt;
			}
			dfs(k, cnt);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		//建adjacent list
		v[x].push_back(y);
		v[y].push_back(x);
	}

	memset(visited, 0, sizeof(visited));
	dfs(0, 0);
	memset(visited, 0, sizeof(visited));
	dfs(far_index, 0);

	cout << max_cnt << endl;

	return 0;
}
