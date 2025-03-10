#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#define taskname "B"
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
       freopen(taskname".out", "w", stdout);
    }
}

void Solve(){
ll n;cin >> n;
    string ans[4] = {"north", "east", "south", "west"};
    int wrong = 0; 
    for (int i = 0; i < n; ++i) {
        string s;cin >> s;
        if (s == "left") {
            wrong = (wrong + 3) % 4; 
        } else if (s == "right") {
            wrong = (wrong + 1) % 4; 
        } else if (s == "back") {
            wrong = (wrong + 2) % 4; 
        }
    }
    cout << ans[wrong] << endl;
}
int32_t main(){
	Input();
	Solve();
	return 0;
}