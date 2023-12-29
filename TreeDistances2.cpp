#include<iostream>
#include<vector>
#define int long long

using namespace std;

const int N = 200005;

vector<int>adj[N],ans(N,0), subtreeSize(N,0), subtreeAns(N,0);

void preprocess(int node, int parent){
    subtreeSize[node] = 1;
    for(auto i: adj[node]){
        if(i!=parent){
            preprocess(i, node);
            subtreeSize[node] += subtreeSize[i];
            subtreeAns[node] += subtreeAns[i] + subtreeSize[i];
        }
    }
}

void solve(int node, int parent, int partial_ans, int total_nodes){
    ans[node] = subtreeAns[node] + partial_ans + (total_nodes - subtreeSize[node]);
    for(auto i:adj[node]){
        if(i!=parent){
            solve(i, node, ans[node] - (subtreeAns[i] + subtreeSize[i])  ,total_nodes);
        }
    }
}
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(1, 0);
    solve(1,0,0,n);
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
