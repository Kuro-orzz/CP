#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

mt19937 rng(time(0));

void sinh(){
    int n = rng() % 100+1;
    int m = rng() % 100+1;
    cout << n << " " << m << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (char)(rng()%26+'a');
        } 
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    freopen("test.inp", "w", stdout);
    int t = 10;
    cout << t << '\n';
    while(t--)
        sinh();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
