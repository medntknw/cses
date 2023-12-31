#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 200005;

vector<int>adj[N], l(N,0);
vector<vector<int> >dp(N, vector<int>(21, -1));

void dfs(int node, int parent, int level){
    l[node] = level;
    dp[node][0] = parent;
    for(int i:adj[node]){
        if(i!=parent){
            dfs(i, node, level+1);
        }
    }
}

void preprocess(int n){
    for(int i=1;1<<i <=n ;i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1]>=0){
                dp[j][i] = dp[dp[j][i-1]][i-1];
            }
        }
    }
}

int lca(int a, int b){
    if(l[a]<l[b])swap(a, b);
    int diff = abs(l[a]- l[b]);
    for(int i = 20; i >= 0; i--) 
		if(diff & (1<<i)) 
		a = dp[a][i];
    if(a==b)return b;

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
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1,0,0);
    preprocess(n);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}