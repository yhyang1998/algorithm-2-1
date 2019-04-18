#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long
#define INF 2147483647
using namespace std;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll sum = 0, maxx = -INF;
	int n, l, r, tmp = 1;

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		if(a[i] > 0 && sum < 0){
			sum = 0;	//因為原本的sum比a[i]小 所以就不要了 直接從a[i]開始從新算
			tmp = i;
		}else if(a[i] < 0){
			if(a[i] > maxx){	//處理第一個輸近來是小於0的情況
				maxx = a[i];
				l = i;
				r = i;
				//cout << "hi!! " << a[i] << endl;
			}
		}
		sum += a[i];	//sum 先放到這個數為止的和 下面再比較要不要把這個數放進去
		if(sum > maxx){
			maxx = sum;
			l = tmp;
			r = i;
		}
	}

	//cout << maxx << endl;
	cout << l << " " << r << endl;

	return 0;
}
