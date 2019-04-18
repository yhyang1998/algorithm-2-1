#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define INF 1e14
#define PII pair<int, int>
#define maxn 1005
#define ll long long 
using namespace std;

vector<PII> vp[maxn];
ll dist[maxn][maxn];

void karp(int n){

}

int main(){
    int n, m, u, v, w;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        --u; --v;
        vp[v].push_back(PII(u,w));
    }
    karp(n);

    return 0;
}
