#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dp[1000006];

void dp_sol() {
    for (int i = 1; i <= 1e6; i++) {
        ll cnt = 0, cur = i;
        while (cur > 1) {
            if (cur <= 1e6 && dp[cur]) {
                cnt += dp[cur];
                break;
            }
            if (cur % 2 == 0) cur /= 2;
            else cur = 3*cur + 1;
            cnt++;
        }
        dp[i] = cnt;
    }
    int pos = 0;
    for (int i = 1; i <= 1e6; i++) {
        if (dp[i] > dp[pos]) pos = i;
    }
    cout << pos;
}

int main() {
    dp_sol();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}