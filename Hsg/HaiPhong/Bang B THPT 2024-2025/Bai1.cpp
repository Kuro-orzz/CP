#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int maxn = 1e5+1;
vector<int> nt;

void sieve(){
    nt.resize(maxn, 1);
    nt[0] = nt[1] = 0;
    for(int i = 2; i*i < maxn; i++)
        if(nt[i])
            for(int j = i*i; j < maxn; j+=i)
                nt[j] = 0;
}

void solve(){
    int l, r; cin >> l >> r;
    sieve();
    int i = ceil(sqrt(l));
    int ans = 0;
    while(i*i <= r){
        if(nt[i])
            ans++;
        i++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
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
