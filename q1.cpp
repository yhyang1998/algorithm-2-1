#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<ll, vector<ll>, greater<ll> > p;	//小到大排

	int n, w;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> w;
		p.push(w);
	}

	/*
	for(int i = 0; i < n-1; i++){
		ll test = p.top();
		p.pop();
		test = 2*(p.top()+test);
		p.pop();
		p.push(test);
	}
	*/


	while(p.size() != 1){	//當p不只有一個元素
		ll test = p.top();
		p.pop();
		test = 2*(p.top()+test);
		p.pop();
		p.push(test);
	}


	cout << p.top() << endl;

}
