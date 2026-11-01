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

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}

// check if equation have any answer
bool any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 *= c/g;
    y0 *= c/g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt*b;
    y -= cnt*a;
}

bool min_sum_sol(ll a, ll b, ll c, ll &x, ll &y) {
    ll g;
    if(!any_solution(a, b, c, x, y, g))
        return false;
    a /= g;
    b /= g;
    ll sign_a = a > 0 ? 1 : -1;
    ll sign_b = b > 0 ? 1 : -1;
    shift(x, y, a, b, (0 - x) / b);
    if (x < 0) shift(x, y, a, b, sign_b);
    if (y < 0) {
        shift(x, y, a, b, -(0 - y) / a);
        if (y < 0) shift(x, y, a, b, -sign_a);
    }
    return true;
}

// a1*x1 + b1 = a2*x2 + b2  <=>  a1*x1 + (-a2)*x2 = b2 - b1
void solve(){
    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    ll x1, x2;
    if(a1 == 0 && a2 == 0) x1 = 0, x2 = 0;
    else if(a1 == 0) x1 = 0, x2 = (b1 - b2) / a2;
    else if(a2 == 0) x1 = (b2 - b1) / a1, x2 = 0;
    else min_sum_sol(a1, -a2, b2 - b1, x1, x2);
    cout << x1 << ' ' << x2 << '\n';
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
