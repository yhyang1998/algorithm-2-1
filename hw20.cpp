#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define INF 1e17
#define ll long long
#define PII pair<int, int>
#define maxn 1005
using namespace std;

vector<PII> vp[maxn];
ll dst[maxn][maxn];

void karp(int n){
    for(int i=0; i<n; i++)
        if(!vp[i].empty())
            vp[n].push_back(PII(i,0));
    n++;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dst[i][j]=INF;

    dst[0][n-1] = 0;

    for (int k=1; k<=n; k++)
        for (int u=0; u<n; u++){
            if(dst[k-1][u]==INF) continue;

            for(int i=vp[u].size()-1; i>=0; i--)
                dst[k][vp[u][i].first] = min(dst[k][vp[u][i].first], dst[k-1][u]+vp[u][i].second);
        }

    double ans = 1e15;

    for(int u=0; u+1<n; u++){
        if(dst[n][u]==INF) continue;
        double W = -1e15;

        for(int k=0; k<n; k++)
            if(dst[k][u]!=INF)
                W = max(W,(double)(dst[n][u]-dst[k][u])/(n-k));

        ans = min(ans,W);
    }

    cout << ans << endl;
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
