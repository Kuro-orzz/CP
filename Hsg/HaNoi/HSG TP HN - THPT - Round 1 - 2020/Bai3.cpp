#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve1(){
    int n, m; cin >> n >> m;
    vector<pii> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i].fi >> a[i].se;
    map<int, int> mp;
    mp[1] = mp[n] = 0;
    for(int i = 0; i < m; i++){
        mp[a[i].fi] = 0;
        mp[a[i].se] = 0;
    }
    for(int i = 0; i < m; i++){
        if(a[i].fi <= a[i].se){
            mp[a[i].fi]++;
            mp[a[i].se+1]--;
        }
        else{
            mp[a[i].fi]++;
            mp[n+1]--;
            mp[1]++;
            mp[a[i].se+1]--;
        }
    }
    int mx = 0, sum = 0;
    vector<pii> pre;
    for(auto &it : mp){
        sum += it.se;
        mx = max(mx, sum);
        it.se = sum;
        pre.push_back({it.fi, sum});
    }
    int ans = 0;
    int l = 0, r = 0;
    for(auto it : mp){
        if(!l && it.se == mx)
            l = it.fi;
        if(it.se == mx) r = it.fi;
        else{
            if(l && r){
                ans += r-l+1;
                l = r = 0;
            }
        }
    }
    if(l && r) ans += r-l+1;
    cout << mx << " " << ans;
}

const int maxn = 1e6+6;
int st[maxn*4], lazy[maxn*4];

void push(int id){
    if(lazy[id]){
        st[id*2] += lazy[id];
        st[id*2+1] += lazy[id];
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

int get(int id, int l, int r, int pos){
    if(pos > r || pos < l) return 0;
    if(l == r) return st[id];
    push(id);
    int mid = (l+r)>>1;
    if(pos <= mid) return get(id*2, l, mid, pos);
    else return get(id*2+1, mid+1, r, pos);
}

void update(int id, int l, int r, int u, int v, int val){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        st[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = st[id*2]+st[id*2+1];
}

void solve2(){
    int n, m; cin >> n >> m;
    vector<pii> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i].fi >> a[i].se;
    set<int> s;
    for(int i = 0; i < m; i++){
        s.insert(a[i].fi);
        s.insert(a[i].se);
    }
    s.insert(1); 
    s.insert(n);
    map<int, int> mp1, mp2;
    int cnt = 1;
    for(int i : s){
        mp1[i] = cnt;
        mp2[cnt] = i;
        if(s.count(i+1)) cnt++;
        else cnt += 2;
    }
    for(int i = 0; i < m; i++){
        int l = a[i].fi, r = a[i].se;
        if(l <= r) update(1, 1, mp1[n], mp1[l], mp1[r], 1);
        else{
            update(1, 1, mp1[n], mp1[l], mp1[n], 1);
            update(1, 1, mp1[n], mp1[1], mp1[r], 1);
        }
    }
    int mx = -1;
    int ans = 0;
    int l = 0, r = 0;
    for(int i = 1; i <= mp1[n]; i++)
        mx = max(mx, get(1, 1, mp1[n], i));
    for(int i = 1; i <= mp1[n]; i++){
        if(!l && get(1, 1, mp1[n], i) == mx)
            l = mp2[i];
        if(get(1, 1, mp1[n], i) == mx) r = mp2[i];
        else{
            if(l && r){
                ans += r-l+1;
                l = r = 0;
            }
        }        
    }
    if(l && r) ans += r-l+1;
    cout << mx << " " << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve1();
        // solve2();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
