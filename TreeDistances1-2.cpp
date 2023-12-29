#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

const int N = 200005;

vector<int>adj[N], depth(N,0), ans(N,0);

void preprocess(int node, int parent){
    for(auto i:adj[node]){
        if(i != parent){
            preprocess(i, node);
            depth[node] = max(depth[node], 1 + depth[i]);
        }
    }
}

void solve(int node, int parent, int partial_ans){
    vector<int>prefixDepth,suffixDepth,children;
    for(auto i:adj[node]){
        if(i!=parent){
            children.push_back(i);
            prefixDepth.push_back(depth[i]);
            suffixDepth.push_back(depth[i]);
        }
    }
    for(int i=1;i<prefixDepth.size();i++){
        prefixDepth[i] = max(prefixDepth[i-1], prefixDepth[i]);
    }
    for(int i=prefixDepth.size()-2; i>=0;i--){
        suffixDepth[i] = max(suffixDepth[i+1], suffixDepth[i]);
    }

    for(int i=0;i<children.size();i++){
        // ignore this node in partial ans of node
        int p_ans;
        int max_depth_child;
        int op1 = (i == 0) ? INT_MIN : prefixDepth[i - 1];
        int op2 = (i == (int)suffixDepth.size() - 1) ? INT_MIN : suffixDepth[i + 1];
        max_depth_child = max(op1, op2);
        p_ans = 1 + max(max_depth_child, partial_ans);
        solve(children[i], node, p_ans);
    }
    // eval ans for node
    ans[node] = 1 + max(partial_ans, (prefixDepth.empty() ? -1 : prefixDepth.back()));
}
int main(){
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
    preprocess(1,0);
    solve(1,0,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}