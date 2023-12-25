#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

const int N = 200005;

vector<int>adj[N];
vector<int>visited(N,0);
int ans=0;

int solve(int node){
    visited[node] = 1;
    vector<int>results;
    for(auto i: adj[node]){
        if(!visited[i]) results.push_back(solve(i));
    }
    if(results.size() == 0) return 1;
    sort(results.begin(), results.end(), greater<int>());
    if(results.size()>=2){
        ans = max(ans, results[0]+results[1]);
    }
    else{
        ans = max(ans, results[0]);
    }
    return results[0] + 1;
}
int main(int argc, char *argv[]){
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
    solve(1);
    cout<<ans;


    return 0;
}