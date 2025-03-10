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

struct fenwick{
    vector<int> BIT;
    fenwick(int n): BIT(n, 0){};
    int get(int x){
        int s = 0;
        while(x > 0){
            s += BIT[x];
            x -= x&-x;
        }
        return s;
    }
    void update(int pos, int val){
        int n = BIT.size();
        while(pos <= n){
            BIT[pos] += val;
            pos += pos&-pos;
        }
    }
    void update_range(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
};

vi memo(1);

int test(){
    srand(time(NULL));
    int n = rand()%20+1;
    n = 1000;
    cout << n << '\n';
    vi used(n+1, 0);
    REP(i, 1, n){
        int t = rand()%n+1;
        while(used[t])
            t = rand()%n+1;
        used[t] = 1;
        memo.push_back(t);
        cout << t << '\n';
    }
    return n;
}

void trau(int n, vi &a){
    cout << "-----\n";
    REP(i, 1, n){
        int cnt = 0;
        if(i % 2 != 0){
            int pos = 0;
            REP(j, 1, n){
                if(a[j] == i/2+1)
                    pos = j;
            }
            for(int j = pos; j > i/2+1; j--)
                swap(a[j], a[j-1]), cnt++;
        }
        else{
            int pos = 0;
            REP(j, 1, n){
                if(a[j] == n-i/2+1)
                    pos = j;
            }
            for(int j = pos; j < n-i/2+1; j++)
                swap(a[j], a[j+1]), cnt++;
        }
        cout << cnt << '\n';
    }
}

void solve(){
    int n; cin >> n;
    vi a(n+1);
    vi pos(n+1);
    REP(i, 1, n){
        cin >> a[i];
        pos[a[i]] = i;
    }   
    fenwick f(n+2);
    REP(i, 1, n){
        if(i % 2 != 0){
            cout << abs(i/2+1-abs(pos[i/2+1]+f.get(pos[i/2+1]))) << '\n';
            f.update_range(1, pos[i/2+1], 1);
        }
        else{
            cout << abs(n-i/2+1-abs(pos[n-i/2+1]+f.get(pos[n-i/2+1]))) << '\n';
            f.update_range(pos[n-i/2+1], n, -1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // int t; cin >> t;
    // while(t--)
    // trau(test(), memo);
        solve();
    return 0;
}
