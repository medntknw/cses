#include<iostream>
#include<vector>

using namespace std;

const int N = 200005;

int dfs(int node, vector<int>&visited, vector<int>&ans, vector<int> (&adj)[N]){
    int subs=1;
    for(auto i: adj[node]){
        if(!visited[i]){
            subs += dfs(i, visited, ans, adj);
        }
    }
    ans[node] = subs;
    return subs;
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>adj[N];
    vector<int>visited(n+1, 0);
    vector<int>ans(n+1, 0);
    for(int i=2;i<=n;i++){
        int parent;
        cin>>parent;
        adj[parent].push_back(i);
    }
    dfs(1, visited, ans, adj);
    for(int i=1;i<=n;i++){
        cout<<ans[i]-1<<" ";
    }

    return 0;
}