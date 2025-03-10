#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    map<int, vector<int>> mp;
    int m = 0;
    for(int i = 1; i < a.size(); i++){
        if(a[i] != a[i-1])
            m = (m+a[i]-a[i-1]) % k;
        mp[m].push_back(a[i]);
    }
    int check = 0;
    for(auto it : mp){
        if(it.se.size() % 2 == 1){
            if(n % 2 == 1 && check == 0){
                check++;
            }
            else{
                cout << "-1\n";
                return;
            }
        }
    }
    ll ans = 0;
    for(auto it : mp){
        if(it.se.size() % 2 == 1 && it.se.size() > 1){
            int t = INT_MAX;
            vector<int> dp = {0, 0};
            for(int i = 0; i < it.se.size(); i++){
                dp.push_back(dp[i]+it.se[i]);
            }
            for(int i = 0; i < it.se.size(); i++){
                if(i % 2 == 0)
                    t = min(t, dp[i+1]-dp[i]+(dp[dp.size()-1]-dp[i+2])-(dp[dp.size()-2]-dp[i+1]));
                else
                    t = min(t, dp[i]-dp[i+1]+(dp[dp.size()-1]-dp[i+1])-(dp[dp.size()-2]-dp[i+2]));
            }
            ans += t/k;
        }
        else{
            for(int i = 0; i < it.se.size()-1; i+=2)
                ans += (it.se[i+1]-it.se[i]) / k;
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