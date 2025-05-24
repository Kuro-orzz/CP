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
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    string s; cin >> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == s[0]){
                if(i+(int)s.size() <= n){
                    bool ch = true;
                    for(int k = i; k < i+s.size(); k++)
                        if(a[k][j] != s[k-i])
                            ch = false;
                    if(ch){
                        cout << "YES";
                        return;
                    }
                }
                if(i-(int)s.size()+1 >= 0){
                    bool ch = true;
                    for(int k = i; k > i-(int)s.size(); k--)
                        if(a[k][j] != s[i-k])
                            ch = false;
                    if(ch){
                        cout << "YES";
                        return;
                    }
                }
                if(j+(int)s.size() <= m){
                    bool ch = true;
                    for(int k = j; k < j+s.size(); k++)
                        if(a[i][k] != s[k-j])
                            ch = false;
                    if(ch){
                        cout << "YES";
                        return;
                    }
                }
                if(j-(int)s.size()+1 >= 0){
                    bool ch = true;
                    for(int k = j; k > j-(int)s.size(); k--)
                        if(a[i][k] != s[j-k])
                            ch = false;
                    if(ch){
                        cout << "YES";
                        return;
                    }
                }
            }
        }
    cout << "NO";
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