/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

int num_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll DAY, MONTH, YEAR;

bool isLeapYear(ll year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void solve() {
    ll x, d, m, y; cin >> x >> d >> m >> y;

    // convert to d=1 m=1 y=1
    x += d-1; // d=1
    for (int i = 1; i < m; i++) x += num_day[i]; // m=1
    if (isLeapYear(y) && m > 2) x++;
    x += (y-1) * 365 + (y-1)/4 - (y-1)/100 + (y-1)/400; // y=1

    // YEAR
    int cycle = 365 * 400 + 400/4 - 400/100 + 400/400;
    YEAR = x / cycle * 400 + 1;
    x %= cycle;
    while (true) {
        if (x >= 366 && isLeapYear(YEAR)) {
            x -= 366;
            YEAR++;
        } else if (x >= 365 && !isLeapYear(YEAR)) {
            x -= 365;
            YEAR++;
        }
        else break;
    }

    // MONTH
    if (isLeapYear(YEAR)) num_day[2] = 29;
    else num_day[2] = 28;
    MONTH = 1;
    while (true) {
        if (x >= num_day[MONTH]) {
            x -= num_day[MONTH++];
        } else break;
    }
    // DAY
    DAY = x + 1;

    cout << DAY << " " << MONTH << " " << YEAR;
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}