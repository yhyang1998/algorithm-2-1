#include <bits/stdc++.h>
#define maxn 10005	//	n的大小
#define maxm 100005
#define PII pair<int, int>
using namespace std;

int n, m;
int root[maxn];	//一開始每個node的root都是自己
pair<int, PII> node[maxm];	//存總共有幾組走道

bool cmp(pair<int, PII> a, pair<int, PII> b){
	return a.first > b.first;
}

int find(int r){
	if(root[r] == r)	return r;
	else return(find(root[r]));
}

int main(){
	int x, y, w;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)	root[i] = i;

	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &x, &y, &w);
		node[i].first = w;
		node[i].second.first = x;
		node[i].second.second = y;
	}

	sort(node, node+m, cmp);

	for(int i = 0; i < m; i++){
		int rmin, r1, r2;
		r1 = find(node[i].second.first);
		r2 = find(node[i].second.second);
		//rmin = min(r1, r2);
		if(r1 != r2){	//兩個沒連在一起
			root[r1] = r2;
			//root[r1] = rmin;
		}//else if(r1 == r2)	continue;

		if(find(0) == find(n-1)){
			cout << node[i].first;
			break;
		}

	}



	return 0;
}
