#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    auto isValid = [&](int n, int m, pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool ch = true;
            int t = 0;
            // cout << "t: ";
            for(int k = 0; k < 4; k++){
                pii u = {i+dx[k], j+dy[k]};
                if(isValid(n, m, u)){
                    if(a[i][j] <= a[u.fi][u.se])
                        ch = false;
                    t = max(t, a[u.fi][u.se]);
                    // cout << t << " ";
                }
            }
            // cout << '\n';
            if(ch)
                a[i][j] = t;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}