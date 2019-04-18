#include <iostream>
#include <string>
#define ASCII first
#define times second
#define PII pair<int, int>
using namespace std;

bool cmp(PII a, PII b){
	if(a.times == b.times)	return a.ASCII < b.ASCII;
	else return a.times > b.times;
}

int main(){
	PII ch[30];
	string a;
	cin >> a;
	int len = a.length();

	for(int i = 0; i < len; i++){
		ch[a[i] - 'A'].ASCII = int(a[i]);
		ch[a[i] - 'A'].times++;
	}

	sort(ch, ch+30, cmp);
	for(int i = 0; i < 30; i++){
		if(ch[i].times != 0)		printf("%d %d\n", ch[i].ASCII, ch[i].times);
			//cout << ch[i].first << " " << ch[i].second << endl;
	}
	return 0;
}
