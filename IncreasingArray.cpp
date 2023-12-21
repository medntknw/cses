#include<iostream>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    long long moves = 0;
    for(int i=1;i<n;i++){
        int pe = arr[i-1];
        int ce = arr[i];
        if(ce<pe){
            moves += pe-ce;
            arr[i] = pe;
        }
    }
    cout<<moves;
}

int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}