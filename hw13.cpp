#include <bits/stdc++.h>
#define maxn 3005
#define PII pair<int, int>
#define first w
#define second d
using namespace std;

bool cmp(PII a, PII b){
	return(a.d - b.w > b.d - a.w);
}

int main(){
	int n, w, d;
	int dp[maxn];
	PII box[maxn];
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> w >> d;
		box[i].w = w;
		box[i].d = d-w;
	}
	sort(box, box+n, cmp);

	memset(dp, -1, sizeof(dp));

	int cnt = 0;
	while(cnt < n){
		cnt++;
		for(int i = 0; i < n; i++)
		dp[cnt] =
	}
	for(int i = 0; i < n; i++){
		if(box[i].d >= 0)

			dp[i] =
		}
	}



	return 0;
}

/*
若有兩個box 分別是box1(w1, d1), box2(w2, d2) (這裡的d是已經減掉自己重量後的值 而不是一開使輸進來的)
則他們疊起來之後新的w會是w1+w2, 新的d會是d1-w2或是d2-w1 (看哪個box放下面)
而因為題目要找最高可以放幾層 所以新的d必較大的要放最下面
這樣一直疊上去時 就不用管下面的d是多少 只要管最上面的d

因為可以把題目拆成小部分 所以要用dp解題
dp[當前塔高度] = 能承受的最大重量
*/
