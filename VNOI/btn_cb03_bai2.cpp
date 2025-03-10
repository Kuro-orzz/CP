// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("DOANNT.inp", "r", stdin);
#define fileout() freopen("DOANNT.out", "w", stdout);
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
int a[N+1];
void solve(){
    int q; cin >> q;
    sieve();
    int cnt = 0;
    for(int i = 0; i <= N; i++){
        if(nt[i]) cnt++;
        a[i] = cnt;
    }
    while(q--){
        int l, r; cin >> l >> r;
        if(l > 0)
            cout << a[r]-a[l-1] << '\n';
        else
            cout << a[r] << '\n';
    }
}

int main(){
    fast();
    filein(); fileout();    
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
