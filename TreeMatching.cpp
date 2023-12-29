#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 200005;
vector<int>adj[N];
vector<vector<int> >dp(N, vector<int>(2,0));

void solve(int node, int parent){
    vector<int>prefixsum, suffixsum;
    vector<int>children;
    for(auto i: adj[node]){
        if(i!=parent) children.push_back(i);
    }
    for(auto i: children){
        solve(i, node);
        prefixsum.push_back(max(dp[i][0], dp[i][1]));
        suffixsum.push_back(max(dp[i][0], dp[i][1]));
        dp[node][0] += max(dp[i][0], dp[i][1]);
    }
    for(int i=1;i<prefixsum.size();i++){
        prefixsum[i]+=prefixsum[i-1];
    }
    for(int i=suffixsum.size()-2;i>=0;i--){
        suffixsum[i]+=suffixsum[i+1];
    }
    for(int idx=0;idx<children.size();idx++){
        int selected_node = children[idx];
        int sum_non_selected = 0;
        if(idx>0 && idx<prefixsum.size()-1){
            sum_non_selected = prefixsum[idx-1] + suffixsum[idx+1];
        }
        if(idx == 0) {
            sum_non_selected = suffixsum[idx+1];
        }
        if(idx == prefixsum.size()-1){
            sum_non_selected = prefixsum[idx-1];
        }
        dp[node][1] = max(dp[node][1], 1 + dp[selected_node][0] + sum_non_selected);
        
    }
}
int main(int argc, char*argv[]){
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
    solve(1,0);
    cout<<max(dp[1][0], dp[1][1]);
    return 0;
}
