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
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> v(26);
    for(int i = 0; i < n; i++)
        v[s[i]-'a'].push_back(i);
    int ans = 0;
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++){
            if(i != j){
                int p1 = 0, p2 = 0;
                int cnt1 = 0, cnt2 = 0;
                int cur = 0;
                while(p1 < v[i].size() && p2 < v[j].size()){
                    if(v[i][p1] < v[j][p2]){
                        cur++;
                        p1++;
                        cnt1++;
                    }
                    else{
                        cur--;
                        p2++;
                        cnt2++;
                    }
                    while(p1 < v[i].size()){
                        cur++;
                        p1++;
                        cnt1++;
                    }
                    if(cnt1 && cnt2) ans = max(ans, cur);
                    if(cur < 0) cnt1 = cnt2 = cur = 0;
                } 
            }
        }
    cout << ans;
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
