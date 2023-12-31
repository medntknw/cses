#include<iostream>
#include<vector>
#include<algorithm>
#define SZ 200005

using namespace std;

vector<int>adj[SZ];
int dp[SZ][21];
int level[SZ];

void dfs(int node, int parent, int l){
    dp[node][0] = parent;
    level[node] = l;
    for(int i:adj[node]){
        if(i!=parent){
            dfs(i, node, l+1);
        }
    }
}

void preprocess(int n){
    for(int i=1;1<<i <=n ;i++){
        for(int j=0;j<=n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b){
    if(level[a]<level[b])swap(a,b);
    int diff = abs(level[a]-level[b]);
    for(int i=20;i>=0;i--){
        if(diff & (1<<i)){
            a = dp[a][i];
        }
    }
    if(a == b) return b;
    for(int i=20;i>=0;i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1,0);
    preprocess(n);
    while(q--){
        int a,b;
        cin>>a>>b;
        int LCA = lca(a, b);
        cout<< level[a] + level[b] - 2*level[LCA]<<endl;
    }
    return 0;
}