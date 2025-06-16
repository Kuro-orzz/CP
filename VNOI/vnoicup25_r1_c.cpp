#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

template <int32_t mod>
struct ModInt {
    int32_t x;

    ModInt(): x(0) {}
    ModInt(int32_t _x): x(_x % mod) { x = x < 0 ? x + mod : x; }

    ModInt &operator += (const ModInt &p) {
        x += p.x;
        if (x >= mod) x -= mod;
        return *this;
    }

    ModInt &operator -= (const ModInt &p) {
        x -= p.x;
        if (x < 0) x += mod;
        return *this;
    }

    ModInt &operator *= (const ModInt &p) {
        x = (int32_t)(1ll * x * p.x % mod);
        return *this; 
    }

    ModInt &operator /= (const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    // ModInt += Int
    ModInt &operator += (int32_t t) { return *this += ModInt(t); }
    ModInt &operator -= (int32_t t) { return *this -= ModInt(t); }
    ModInt &operator *= (int32_t t) { return *this *= ModInt(t); }
    ModInt &operator /= (int32_t t) { return *this /= ModInt(t); }

    ModInt operator - () const { return ModInt(-x); } // -a;
    ModInt operator + () const { return ModInt(*this); } // +a;
    ModInt &operator ++ () { *this += 1; return *this; } // ++a;
    ModInt &operator -- () { *this -= 1; return *this; } // --a;
    ModInt operator ++ (int) { ModInt res = *this; *this += 1; return res; } // a++;
    ModInt operator -- (int) { ModInt res = *this; *this -= 1; return res; } // a--;

    // ModInt = ModInt + ModInt
    ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }

    // ModInt = ModInt + Int
    ModInt operator + (int32_t t) const { return ModInt(*this) += t; }
    ModInt operator - (int32_t t) const { return ModInt(*this) -= t; }
    ModInt operator * (int32_t t) const { return ModInt(*this) *= t; }
    ModInt operator / (int32_t t) const { return ModInt(*this) /= t; }

    // ModInt = Int + ModInt
    friend ModInt operator + (int32_t t, const ModInt &p) { ModInt res(t); res += p; return res; }
    friend ModInt operator - (int32_t t, const ModInt &p) { ModInt res(t); res -= p; return res; }
    friend ModInt operator * (int32_t t, const ModInt &p) { ModInt res(t); res *= p; return res; }
    friend ModInt operator / (int32_t t, const ModInt &p) { ModInt res(t); res /= p; return res; }

    bool operator == (const ModInt &p) const { return x == p.x; }
    bool operator != (const ModInt &p) const { return x != p.x; }
    bool operator < (const ModInt &p) const { return x < p.x; }
    bool operator <= (const ModInt &p) const { return x <= p.x; }
    bool operator > (const ModInt &p) const { return x > p.x; }
    bool operator >= (const ModInt &p) const { return x >= p.x; }

    bool operator == (int32_t t) const { return x == t; }
    bool operator != (int32_t t) const { return x != t; }
    bool operator < (int32_t t) const { return x < t; }
    bool operator <= (int32_t t) const { return x <= t; }
    bool operator > (int32_t t) const { return x > t; }
    bool operator >= (int32_t t) const { return x >= t; }

    ModInt inverse() const { return power(mod - 2); }

    ModInt power(int32_t b) const {
        assert(b >= 0);
        ModInt mul(x), ret(1);
        while (b) {
            if (b & 1) ret *= mul;
            mul *= mul;
            b /= 2;
        }
        return ret;
    }

    friend istream &operator >> (istream &in, ModInt &p) { 
        int32_t t;
        in >> t;
        p = ModInt<mod>(t);
        return in;
    }
    
    friend ostream &operator << (ostream &out, const ModInt &p) { return out << p.x; }

    int32_t get() const { return x; }
    static constexpr int32_t get_mod() { return mod; }
};

using mint = ModInt<MOD>;

void solve() {
    int n, q; cin >> n >> q;
    vector<mint> stock_cnt(n), acc_profit(n), stock_price_index(n);
    mint acc_stock_price = 0;

    auto realize_profit = [&](int p) {
        mint stock_price = acc_stock_price - stock_price_index[p];
        stock_price_index[p] = acc_stock_price;
        acc_profit[p] += stock_cnt[p] * stock_price;
    };

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int p, x; cin >> p >> x;
            p--;
            realize_profit(p);
            stock_cnt[p] += x;
        } else if (type == 2) {
            int v; cin >> v;
            acc_stock_price += v;
        } else if (type == 3) {
            int p; cin >> p;
            p--;
            realize_profit(p);
            cout << exchange(acc_profit[p], 0) << '\n';
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
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
