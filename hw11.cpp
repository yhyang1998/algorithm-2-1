#include <bits/stdc++.h>
#include <stdio.h>
#define maxn 3005
#define ll long long
#define time first
#define value second
#define PII pair<int, int>
using namespace std;

bool cmp(PII a, PII b){
	if(a.time == b.time)	return a.value > b.value;
	else return a.time < b.time;
}

PII data[maxn];
ll dp[maxn];
int main(){
	int n, T;
	cin >> n >> T;
	memset(dp, 0, maxn);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &data[i].time, &data[i].value);
	}
	sort(data, data+n, cmp);

	//一個值進來就更新一次dp 每跑一次回圈指的是做第0個到第i個mission的最大價值
	for(int i = 0; i < n; i++){	//紀錄data
		for(int j = T; j-data[i].time >= 0  ; j--){	//紀錄dp j是時間
			dp[j] = max(dp[j], dp[j-data[i].time] + data[i].value);
		}
	}

	printf("%lld\n", dp[T]);
	return 0;
}
