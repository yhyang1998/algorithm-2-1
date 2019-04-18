#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int main(){
	int n, m;
	int cnt[maxn], sum[maxn];
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		cnt[temp]++;
	}
	for(int i = 1; i < maxn; i++)	sum[i] = sum[i-1] + cnt[i];
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d%d", &l, &r );
		printf("%d\n", sum[r]-sum[l-1]);
		//cout << sum[r]-sum[l-1] << endl;	//	有包含sum[l];
	}

	return 0;
}
//scanf printf 真的比cin cout快很多欸....
