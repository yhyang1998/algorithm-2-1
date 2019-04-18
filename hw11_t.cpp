#include <bits/stdc++.h>
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

int main(){
	int n, T;
	PII data[maxn];
	ll dp[maxn][maxn];	//代表dp[n][T]
	memset(dp, 0, maxn);

	cin >> n >> T;
	for(int i = 0; i < n; i++){
		cin >> data[i].time >> data[i].value;
	}
	sort(data, data+n, cmp);

	//一個值進來就更新一次dp 每跑一次回圈指的是 做第0個到第n個mission的最大價值
	for(int i = 0; i < n; i++){	//紀錄data
		for(int j = 0; j < T; j++){	//j代表總時間
			if(j - data[i].time < 0){
				dp[i][j] = dp[]
			}
		}
	}


	return 0;
}
