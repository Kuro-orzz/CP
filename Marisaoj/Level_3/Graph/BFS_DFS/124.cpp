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

const int N = 1e3+6;
int n, vis[N];
int a[N], b[N];
double dist[N][N];
double epsilon = 1e-7;

bool bfs(double R) {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && dist[u][v] <= R) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return cnt == n;
}

double calc(int i, int j) {
    double t1 = a[i] - a[j];
    double t2 = b[i] - b[j];
    return sqrt(t1 * t1 + t2 * t2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = dist[j][i] =  calc(i, j);           
        }
    }
    double l = 0, r = 2e9;
    while (r-l >= epsilon) {
        double mid = (r - l) / 2 + l;
        if (bfs(2*mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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