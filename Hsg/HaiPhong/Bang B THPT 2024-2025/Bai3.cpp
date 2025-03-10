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
    int n, m; cin >> n >> m;
    int team1 = 0;
    int team2 = 0;
    int cnt1 = n;
    int cnt2 = m;
    vector<pii> v1;
    for(int i = 0; i < n+m; i++){
        int a, b, c; cin >> a >> b >> c; 
        if(c == 1){
            team1 += a;
            cnt1--;
        }
        else if(c == 2){
            team2 += b;
            cnt2--;
        }
        else
            v1.push_back({a, b});
    }
    sort(all(v1));
    vector<pii> v2 = v1;
    sort(all(v2), [&](pii a, pii b){
        return a.se < b.se;
    });
    for(pii x : v1)
        cout << x.fi << " " << x.se << '\n';
    cout << '\n';
    for(pii x : v2)
        cout << x.fi << " " << x.se << '\n';
    set<pii> s;
    cout << team1 << " " << team2 << '\n';
    int p1 = 0, p2 = 0;
    for(int i = 0; i < cnt1+cnt2; i++){
        while(s.count(v1[p1]))
            p1++;
        while(s.count(v2[p2]))
            p2++;
        if(cnt1 && v1[p1].fi <= v2[p2].se){
            team1 += v1[p1].fi;
            s.insert(v1[p1]);
            p1++;
            cnt1--;
        }
        else{
            team2 += v2[p2].se;
            s.insert(v2[p2]);
            p2++;
            cnt2--;
        }
    }
    cout << team1+team2;
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
