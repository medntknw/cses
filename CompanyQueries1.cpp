#include<iostream>
#include<vector>

using namespace std;

const int N = 200005;

vector<int>adj[N];
vector<vector<int> >dp(N, vector<int>(21, -1));

void dfs(int node, int parent){
    dp[node][0] = parent;
    for(int i: adj[node]){
        if(i!=parent){
            dfs(i, node);
        }
    }
}

void preprocess(int n){
    for(int i=1; 1<<i <=n; i++){
        for(int j=1;j<=n;j++){
            if(dp[j][i-1] >=0) dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
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
    dfs(1,-1);
    preprocess(n);
    while(q--){
        int x,k;
        cin>>x>>k;
        int bit = 0, boss=x;
        for(int i=0;i<=20;i++){
            if(k&(1<<i)){
                boss = dp[boss][i];
                if(boss<=0){
                    break;
                }
            }
        }
        cout<<boss<<endl;
    }
    return 0;
}