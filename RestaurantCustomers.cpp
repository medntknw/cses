#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include <cstring>
#include<queue>
 
using namespace std;
 
struct Comparator {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
 
int main(int argc, char *argv[]){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, Comparator>q;
    for(auto i:v){
        while(!q.empty() && q.top().second < i.first){
            q.pop();
        }
        q.push(i);
        ans = max(ans, (int)q.size());
    }
    ans = max(ans, (int)q.size());
    cout<<ans;
