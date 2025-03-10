#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int sum_digit(string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res += s[i]-'0';
    return res;
}

void solve(){
    string s; cin >> s;
    int d = sum_digit(s)%9;
    if(d == 0){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '9'){
                s[i] = '0';
                cout << s << '\n';
                return;
            }
        }
        cout << s << '\n';
        return;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i]-'0' >= d){
            s[i] -= d;
            cout << s << '\n';
            return;
        }
    }
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i]-'0' <= d){
            s[i] += 9-d;
            cout << s << '\n';
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
