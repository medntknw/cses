#include<iostream>

using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
    }
    else if(n<=3){
        cout<<"NO SOLUTION";
    }
    else{
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }

}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}