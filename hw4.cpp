#include <bits/stdc++.h>
#include <string>
using namespace std;

int Compare(string s, string t){

	int slen = s.length();
	int tlen = t.length();

	string shl = s.substr(0, slen/2);
	string shr = s.substr(slen/2, slen/2);
	string thl = t.substr(0, tlen/2);
	string thr = t.substr(tlen/2, tlen/2);


	//有三種情況可以直接return
	if(s == t)	return 1;
	if(slen != tlen)	return 0;
	if((slen%2) != 0 || (tlen%2) != 0)	return 0;
	else{

		if(Compare(shl, thl) && Compare(shr, thr))	return 1;	//shl == thl && shr ==thr
		else if(Compare(shl, thr) && Compare(shr, thl))	return 1;	//shl == the && shr == thl
		else return 0;
	}

}

int main(){
	string s, t;
	cin >> s >> t;
	if(Compare(s, t))	cout << "YES\n";
	else	cout << "NO\n";
	return 0;

}
