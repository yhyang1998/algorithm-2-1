#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 1000005
using namespace std;

int main(){
	int n, m, temp;
	int num[maxn], dp[maxn];

	cin >> n >> m;
	memset(num, 0, sizeof(num));
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < m; i++){
		cin >> temp;
		dp[temp] = 1;
		num[i] = temp;
	}
	sort(num, num+m);

	for(int j = 1; j <= n; j++){			//j紀錄sum
		for(int i = 0; i < m; i++){
			if(j < num[i])	break;
			else{
				dp[j] += dp[j-num[i]];
				dp[j] %= mod;
			}
		}
		dp[j] %= mod;
		//printf("dp[%d] = %d\n", j, dp[j]);
	}
	cout << dp[n] << endl;

	return 0;
}
