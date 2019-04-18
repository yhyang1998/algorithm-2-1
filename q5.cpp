#include <bits/stdc++.h>
#include <unordered_map>
#define maxn 1505
#define ll long long
using namespace std;

int a[maxn], b[maxn], c[maxn], d[maxn];

int main(){
	unordered_map<ll , int> m;	//key存加起來要是什麼數 value存有幾組數加起來是這個key值
	ll x, count = 0;	//四個位數加起來要是x
	int n;
	scanf("%d%lld", &n, &x);

	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)	scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)	scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++)	scanf("%d", &d[i]);

	for(int k = n-1; k > 0; k--){	//c向下減
		for(int l = k+1; l <= n; l++){	//d向上增
			ll sumcd = c[k] + d[l];
			m[sumcd] ++;	//找到一組就記錄到map裡
		}

		int j = k-1;
		for(int i = 1; i < j; i++){	//紀錄a
			count += m[x - (a[i] + b[j])];
		}
	}

	printf("%lld\n", count);
}
