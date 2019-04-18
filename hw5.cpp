#include <bits/stdc++.h>
#define maxn 300005
#define num first
#define index second
#define PII pair<int, int>
using namespace std;

bool cmp(PII a, PII b){
	if(a.num == b.num)	return a.index < b.index;
	return a.num > b.num;
}

int main(){
	int n, m;
	PII data[maxn];

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> data[i].num;
		data[i].index = i;
	}
	sort(data, data+n, cmp);

	for(int j = 0; j < m; j++){
		int l, r;
		cin >> l >> r;
		for(int i = 0; i < n; i++){
			if(data[i].index >= l && data[i].index <= r){
				cout << data[i].index << endl;
				break;
			}
		}
	}
	return 0;
}
