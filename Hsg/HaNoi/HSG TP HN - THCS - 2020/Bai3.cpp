// solve1 just exist cuz some testcase was bug:)), solve2 with binary search is better
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

// random hash + binary search
void solve1(){
    mt19937_64 rng(time(0));
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n+1, vector<char>(m));
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<ll> H(26);
    for(int i = 0; i < 26; i++)
        H[i] = rng()%(ll)1e18;
    vector<vector<ll>> v(n+2, vector<ll>(m, 1));
    vector<ll> p(m, 1);
    for(int i = 1; i < m; i++)
        p[i] = p[i-1]*2;
    for(int i = n; i >= 1; i--)
        for(int j = 0; j < m; j++)
            v[i][j] = (v[i+1][j]^H[a[i][j]-'a']+H[a[i][j]-'a']%MOD*p[n-i])%(ll)(1e18);
    int l = 1, r = n-1;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        set<ll> s;
        bool ch = true;
        for(int i = 0; i < m; i++){
            if(s.count(v[mid+1][i]))
                ch = false;
            s.insert(v[mid+1][i]);
        }
        if(ch){
            ans = max(ans, mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans;
}

// binary_serach
bool check(int pos, int n, int m, vector<vector<char>> &a){
    unordered_set<string> s;
    for(int i = 1; i <= m; i++){
        string tmp = "";
        for(int j = pos+1; j <= n; j++)
            tmp += a[j][i];
        if(s.count(tmp)) return false;
        else s.insert(tmp); 
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n+1, vector<char>(m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    int l = 1, r = n-1;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid, n, m, a)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    if(fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin); 
        freopen(TASK".out", "w", stdout); 
    }
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
