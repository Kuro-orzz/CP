// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e6
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006

void solve(){
    int n; cin >> n;
    ll ans = 0;
    bool zero_more_than_one = false;
    bool one_more_than_zero = false;
    bool one_equal_to_zero = false;
    bool only_one = true;
    bool only_zero = true;
    pii move_one = {INF, 0};    // test 2
    pii move_zero = {INF, 0};   // test 3
    int move_equal = INF;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int one = 0;
        int zero = 0;
        for(int j = 0; j < s.size(); j++)
            if(s[j] == '1')
                one++;
            else
                zero++;
        if(one > zero)
            one_more_than_zero = true;
        else if(zero > one)
            zero_more_than_one = true;
        else
            one_equal_to_zero = true;
        ans += min(zero, one);   // test 1 solve

        // test 2 solve
        if(one > zero && one - zero < move_one.fi - move_one.se){
            move_one = {one, zero};
        }
        // test 3 solve
        if(zero > one && zero - one < move_zero.fi - move_zero.se){
            move_zero = {zero, one};
        }
        
        // test 4 + 5 solve
        if(zero == one && zero < move_equal){
            move_equal = zero;
        }
        if(zero > 0)
            only_one = false;
        if(one > 0)
            only_zero = false;
    }
    if(only_one || only_zero){
        cout << 0;
        return;
    }
    // test 1
    if(zero_more_than_one && one_more_than_zero)
        cout << ans;
    // test 2
    else if(one_more_than_zero && !zero_more_than_one && !one_equal_to_zero){
        cout << ans + move_one.fi - move_one.se;
    }
    // test 3
    else if(zero_more_than_one && !one_more_than_zero && !one_equal_to_zero){
        cout << ans + move_zero.fi - move_zero.se;
    }
    // test 4
    else if(one_more_than_zero && !zero_more_than_one && one_equal_to_zero){
        cout << ans;
    }
    // test 5
    else if(zero_more_than_one && !one_more_than_zero && one_equal_to_zero){
        cout << ans;
    }
    // test 6
    else if(!zero_more_than_one && !one_more_than_zero && one_equal_to_zero){
        cout << ans;
    }
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}


