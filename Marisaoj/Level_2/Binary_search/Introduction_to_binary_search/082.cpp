#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1506;
    
vector<ll> v;

void calc(){
    v.resize(1, 1);
    int i = 0, j = 0, k = 0;
    while(v.back() < 1e18){
        v.push_back(min({v[i]*2, v[j]*3, v[k]*5}));
        if(v.back() == v[i]*2) i++;
        if(v.back() == v[j]*3) j++;
        if(v.back() == v[k]*5) k++;
    }
}

int bs(int l, int r, ll x){
    while(l <= r){
        int mid = (l+r)>>1;
        if(v[mid] > x) r = mid-1;
        else if(v[mid] < x) l = mid+1;
        else return mid;
    }
    return -1;
}

void solve(){
    ll n; cin >> n;
    int pos = bs(0, v.size()-1, n);
    if(pos != -1) pos++;
    cout << pos << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    calc();
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}