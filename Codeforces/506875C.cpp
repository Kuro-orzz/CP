// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (int)(1e9+7)
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10000006

bool nt[maxn+1];
vi memo;

void sieve(){
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for(int i = 2; i <= sqrt(maxn); i++){
        if(nt[i]){
            int j = i*i;
            while(j <= maxn){
                nt[j] = false;
                j += i;
            }
        }
    }
    for(int i = 2; i <= maxn; i++){
        if(nt[i])
            memo.pb(i);
    }
}

void solve(){
    int t; cin >> t;
    sieve();
    while(t--){
        int n; cin >> n;
        int i = 0;
        while(nt[memo[i] + n])
            i++;
        cout << memo[i] << '\n';
    }
}   

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}