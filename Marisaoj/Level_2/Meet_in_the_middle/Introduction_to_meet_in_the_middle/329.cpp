#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 41;
ll n, k;
vector<ll> a, val;

void MITM(int i, ll sum, int end) {
    if (sum > k) return;
    if (i >= end) val.push_back(sum);
    else {
        MITM(i+1, sum, end);
        MITM(i+1, sum+a[i], end);
    } 
}

bool two_pointer(ll target) {
    int l = 0, r = val.size()-1;
    while(l < r) {
        if (val[l] + val[r] > target) r--;
        else if (val[l] + val[r] < target) l++;
        else return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    MITM(0, 0, n/2);
    MITM(n/2, 0, n);
    sort(all(val));
    if (two_pointer(k))
        cout << "YES";
    else cout << "NO";
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