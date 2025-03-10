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

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    int positive = 0;
    int negative = 0;
    int t1 = 0, t2 = 0;
    FOR(i, 0, n){
        if(a[i] == 1 && b[i] == 1)
            positive++;
        else if(a[i] == 1)
            t1++;
        else if(b[i] == 1)
            t2++;
        else if(a[i] == -1 && b[i] == -1)
            negative++;
    }
    while(positive || negative){
        if(t1 >= t2 && positive){
            t2++;
            positive--;
        }
        else if(t1 < t2 && positive){
            t1++;
            positive--;
        }
        else if(t1 >= t2 && negative){
            t1--;
            negative--;
        }
        else if(t1 < t2 && negative){
            t2--;
            negative--;
        }
    }
    cout << min(t1, t2) << '\n';    
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}