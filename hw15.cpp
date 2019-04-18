#include <bits/stdc++.h>
#define l first
#define r second
#define PII pair<int, int>
#define maxn 100005
using namespace std;

bool cmp(PII a, PII b){
	if(a.l == b.l)	return a.r > b.r;
	else return a.l < b.l;
}

int main(){
	int w, n;
	PII wifi[maxn];
	memset(wifi, 0, 100005);

	cin >> w >> n;
	for(int i = 0; i < n; i++){
		int x, r;
		cin >> x >> r;
		wifi[i].l = x-r;
		wifi[i].r = x+r;
	}
	sort(wifi, wifi+n, cmp);

	int i = 0, j = 0, now = 0, temp = 0, cnt = 0, range = 0;
	//i紀錄整個wifi迴圈 j紀錄現在跑到哪個 now紀錄被選到的那個 temp紀錄跑動的range cnt是總共有幾個 range是現在的尾端
	while(i < n){
		if(wifi[i].l > range){
			cnt = -1;
			break;
		}else{
			if(wifi[i].l > range)	range = wifi[i].l;

			while(wifi[j].l <= range && j < n){
				if(wifi[j].r >= temp){
					temp = wifi[j].r;
					now = j;
				}
				j++;
			}
			cnt++;
			i = j;
			range = wifi[now].r;
			temp = range;
			if(range >= w)	break;
		}
	}
	if(wifi[now].r < w)	cnt = -1;

	cout << cnt << endl;

	return 0;
}
