#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<int> nt(1e6+1, 1);

void sieve(){
    nt[0] = nt[1] = 0;
    for(int i = 2; i*i <= 1e6; i++)
        if(nt[i])
            for(int j = i*i; j <= 1e6; j += i)
                nt[j] = 0;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v;
    sieve();
    for(int i = 0; i < n; i++)
        if(nt[a[i]])
            v.push_back(i);
    int ans = INT_MAX;
    for(int i = 1; i < v.size(); i++)
        ans = min(ans, v[i]-v[i-1]+1);
    cout << (ans != INT_MAX ? ans : -1);
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
