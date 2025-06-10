#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
 
const int N = 16;
int n, k, a[N], sum, group[N], target;
int ans[N];
bool exist_sol = false;

void backtrack(int idx, int sum, int k_group) {
    if (sum > target) return;
    if (k_group == k+1) {
        for (int i = 0; i < n; i++) {
            ans[i] = group[i];
        }
        exist_sol = true;
        return;
    }
    if (sum == target) {
        backtrack(0, 0, k_group+1);
        return;
    }
    for (int i = idx; i < n; i++) {
        if (group[i]) continue;
        group[i] = k_group;
        backtrack(i+1, sum + a[i], k_group);
        group[i] = 0;
    }
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum = accumulate(a, a+n, 0);
    if (sum % k) cout << "ze";
    else {
        target = sum / k;
        backtrack(0, 0, 1);
        if (!exist_sol) {
            cout << "ze";
            return;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
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