#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 200005;

vector<int>adj[N], visited(N,0), dist(N,0), maxDist(N,0);

void reset(int n){
    for(int i=0;i<=n;i++){
        visited[i] = 0;
        dist[i] = 0;
    }
}
void dfs(int node){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            dist[i] = max(dist[i], dist[node] + 1);
            dfs(i);
        }
    }
};

void bfs(int node){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited[curr] = 1;
        for(auto i: adj[curr]){
            if(!visited[i]){
                q.push(i);
                dist[i] = dist[curr] + 1;
                maxDist[i] = max(maxDist[i], dist[i]);
            }
        }
    }
}

int farthest_node(int n){
    int d=0, x;
    for(int i=1;i<=n;i++){
        if(dist[i] > d){
            d = dist[i];
            x = i;
        }
    }
    return x;
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
    if(n==0 || n==1){
        cout<<0;
        return 0;
    }
    // get farthest node from 1
    dfs(1);
    int x = farthest_node(n);
    // reset vectors
    reset(n);
    // get farthest node from the previous farthest node
    dfs(x);
    int y = farthest_node(n);
    // reset vectors
    reset(n);
    // farthest distance of each node from endpoint 1
    bfs(x);
    // reset vectors
    reset(n);
    // farthest distance of each node from endpoint 2
    bfs(y);
    for(int i=1;i<=n;i++){
        cout<<maxDist[i]<<" ";
    }

    return 0;
}