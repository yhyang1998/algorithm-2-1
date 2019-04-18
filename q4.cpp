#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
int client[3003];	//裝輸入進來的值
int dp[maxn];

int main(){
	int n, m, s;
	int sum_ = 0;
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++){
		int c;
		scanf("%d", &c);
		client[i] = c;
		sum_ += c;	//計算所有client的總和
	}

	m -= s;
	//sort(client, client+n);	//小到大排
	memset(dp, 0, sizeof(dp));	//dp[i]放負重是i時 最多能放多少

	for(int i = 0; i < n; i++){	//由client小到大更新dp值
		for(int j = m; j > 0; j--){	//從大的開始更新回來 因為放過得不能再放！
			if(client[i] <= j){
				dp[j] = max(dp[j], dp[j-client[i]] + client[i]);	//不放 vs 放
			}
			//printf("dp[%d] = %d ", j, dp[j]);
		}
		//printf("\n");
	}

	printf("%d\n", sum_ - dp[m]);

	return 0;
}
