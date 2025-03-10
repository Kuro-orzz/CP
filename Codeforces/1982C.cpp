#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i-1]+a[i];
    int sum = 0;
    int ans = 0;
    deque<int> dq;
    for(int i = n-1; i >= 0; i--){
        sum += a[i];
        dq.push_back(a[i]);
        if(sum > r){
            while(dq.size() && sum > r){
                sum -= dq.front();
                dq.pop_front();
            }
            if(sum >= l && sum <= r){
                ans++;
                sum = 0;
                dq.clear();
            }
        }
        if(sum >= l && sum <= r){
            ans++;
            sum = 0;
            dq.clear();
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}