#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dp_sol() {
    int n = 21;
    vector<vector<ll>> dp(n, vector<ll>(n, 1));
    for(int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[20][20];
}

int main() {
    dp_sol();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}