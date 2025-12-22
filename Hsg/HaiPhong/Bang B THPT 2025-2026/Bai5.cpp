/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

vector<int> sieve_divisors(int n) {
    vector<int> divisors(n+1, 0);
    for (int i = 1; i*i <= n; i++) {
        for (int j = i*i; j <= n; j += i) {
            divisors[j] += 2;
        }
        divisors[i*i]--;
    }
    return divisors;
}

vector<int> segmentSieveDivisors(int l, int r){
    vector<int> div(r-l+1, 0);
    for(ll i = 1; i*i <= r; i++){
        ll lim = max(i*i, (l+i-1)/i*i);
        for(ll j = lim; j <= r; j += i) {
            div[j-l] += 2;
        }
        if (i * i >= l) div[i*i-l]--;
    }
    if (l == 0) div[0] = 0;
    return div;
}

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int mn = *min_element(a, a+n);
    int mx = *max_element(a, a+n);
    vector<int> cnt_div = segmentSieveDivisors(mn, mx);
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && cnt_div[a[st.top()]-mn] < cnt_div[a[i]-mn]) {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    for (int x : ans) cout << x << ' ';
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}