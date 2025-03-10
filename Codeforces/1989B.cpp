#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)
#define MOD (int)(1e9+7)
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int cal(string s1, string s2) {
    int res = 0;
    FOR(k, 0, s2.size()){
        int cnt = 0;
        int pos = 0;
        FOR(i, k, s2.size()){
            bool ch = false;
            FOR(j, pos, s1.size())
                if(s1[j] == s2[i]){
                    cnt++;
                    pos = j+1;
                    ch = true;
                    break;
                }
            if(!ch) cnt = 0, pos = 0;
            res = max(res, cnt);
        }
    }
    return res;
}

void solve(){
    string s1, s2; cin >> s1 >> s2;
    cout << s2.size()-cal(s1, s2)+s1.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}