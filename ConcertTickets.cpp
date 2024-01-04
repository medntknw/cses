#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include <cstring>
#include <set>
 
using namespace std;
 
int main(int argc, char *argv[]){
    int n,m;
    cin>>n>>m;
    int cp[m];
    multiset<int>tp;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        tp.insert(t);
    }
    for(int i=0;i<m;i++)cin>>cp[i];
    for(int i=0;i<m;i++){
        int mx_price = cp[i];
        auto it = tp.lower_bound(mx_price);
        if(it == tp.begin()){
            if(*it == mx_price){
                cout<<*it<<endl;
                tp.erase(it);
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            if(*it == mx_price){
                cout<<*it<<endl;
                tp.erase(it);
            }
            else{
                cout<<*(--it)<<endl;
                tp.erase(it);
            }
        }
        
    }
}