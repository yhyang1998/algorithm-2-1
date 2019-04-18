#include <bits/stdc++.h>
using namespace std;
string s;

int i = -1;
int df(int len){
	i++;
	if(s[i] == '2'){
		int sum = 0;
		for(int j = 0; j < 4; j++){
			sum += df(len/2);
		}
		return sum;
	}
	else if(s[i] == '1')	return len*len;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int len;
	cin >> len >> s;

	int ans = df(len);
	cout << ans;

	return 0;
}
