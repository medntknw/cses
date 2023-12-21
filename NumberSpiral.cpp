#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(){
   ll t;
   cin>>t;
   while(t--){
       ll i,j;
       cin>>i>>j;
       i--;j--;
       if(i>j){
            if(i%2==0){
                cout<<(i*i)+j+1<<endl;
            }
            else{
                cout<<(i+1)*(i+1)-j<<endl;
            }
       }
       else{
        if(j%2 == 0){
            cout<<(j+1)*(j+1)-i<<endl;
        }
        else{
            cout<<(j*j)+i+1<<endl;
        }
       }
   }

}
int main(int argc, char *argv[]){
    solve();
    return 0;
}