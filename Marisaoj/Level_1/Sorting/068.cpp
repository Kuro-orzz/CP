#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Oxyz{
    int x, y, z;
};

bool cmp(Oxyz a, Oxyz b){
    if(a.x != b.x){
        if(a.x > b.x) return false;
        return true;
    }
    if(a.y != b.y){
        if(a.y > b.y) return false;
        return true;
    }
    if(a.z != b.z){
        if(a.z > b.z) return false;
        return true;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vector<Oxyz> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(all(a), cmp);
    for(int i = 0; i < n; i++)
        cout << a[i].x << " " << a[i].y << " " << a[i].z << '\n';
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