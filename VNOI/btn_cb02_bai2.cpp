// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("hangxom.inp", "r", stdin);
#define fileout() freopen("hangxom.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 10000000

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool nt[N+6];
void sieve(){
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for(int i = 2; i <= sqrt(N); i++)
        if(nt[i]){
            int j = i * i;
            while(j <= N){
                nt[j] = false;
                j += i;
            }
        }
}

void solve(){
    int l, r; cin >> l >> r;
    sieve();
    int ans = 0;
    for(int i = l; i <= r-2; i++)
        if(nt[i] && nt[i+2])
            ans++;
    cout << ans;
}

int main(){
    fast();
    filein(); fileout();    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
