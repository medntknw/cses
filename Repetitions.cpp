#include<iostream>
#include<string>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int i=0,j=0;
    int ans=1, curr=0;
    while(j<n && i<=j){
        if(s[i] == s[j]){
            curr++;
            j++;
        }
        else{
            ans=max(ans, curr);
            curr=0;
            i=j;
        }
    }
    ans= max(ans, curr);
    cout<<ans;

}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}