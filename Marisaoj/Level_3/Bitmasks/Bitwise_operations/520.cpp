#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int a, b; cin >> a >> b;
    bitset<15> b1(a), b2(b);
    for(int i = 0; i < 5; i++)
        b1[i] = b1[i] ^ b2[i];
    for(int i = 5; i < 10; i++)
        b1[i] = b1[i] & b2[i];
    for(int i = 10; i < 15; i++)
        b1[i] = b1[i] | b2[i];
    cout << b1.to_ulong() << '\n';    
}
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}