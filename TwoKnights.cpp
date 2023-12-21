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

ll ways(ll n){
    // All combinations to place 2 knights in n*n chessboard
   // xC2 where x = n*n
   // x*(x-1)/2
   ll x = n*n;
   ll num_ways = x*(x-1)/2;
   // A knight cannot be placed in 2 ways in a 2*3 and 3*2 chessboard each.
   // Number of 2*3 in a n*n chessboard -> (n-1)*(n-2)
   ll not_possible = 2*(n-1)*(n-2)*2;
   return num_ways-not_possible;
}
void solve(){
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
    cout<<ways(i)<<endl;
   }
}
int main(int argc, char *argv[]){
    solve();
    return 0;
}