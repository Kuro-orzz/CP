#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve1() {
    vector<int> smallest;
    int triangle = 0;
    int index = 1;
    while (smallest.size() < 1000) {
        int div = 0;
        triangle += index;
        index++;

        int i = 1, cntDiv = 0;
        while (i * i < triangle) {
            if (triangle % i == 0) cntDiv += 2;
            i++;
        }
        while (smallest.size() <= cntDiv) smallest.push_back(triangle);
    }
    // for (int i = 0; i < 1000; i++) cout << i << " " << smallest[i] << '\n';
    cout << smallest[500] << '\n';
}

vector<int> segmentSieve(int l, int r){
    vector<int> prime(r-l+1, 1);
    for(ll p = 2; p*p <= r; p++){
        ll lim = max(p*p, (l+p-1)/p*p);
        for(ll j = lim; j <= r; j += p)
            if (j-l >= 0) prime[j-l] = 0;
    }
    if (l == 0) prime[0] = 0;
    if (l == 0 && r > l) prime[1] = 0;
    if (l == 1) prime[1-l] = 0;
    return prime;
}

vector<int> listPrime(int l, int r) {
    vector<int> prime = segmentSieve(l, r);
    vector<int> listPi;
    for (int i = l; i <= r; i++) {
        if (prime[i-l]) listPi.push_back(i);
    }
    return listPi;
}

void solve2() {
    vector<int> primeArr = listPrime(1, 1e5);
    int cnt = 0, triangle = 0, index = 1;
    while (cnt <= 500) {
        cnt = 1;
        triangle += index;
        index++;

        int tt = triangle;
        for (int x : primeArr) {
            if (x * x > tt) {
                cnt *= 2;
                break;
            }
            int exp = 1;
            while (tt % x == 0) {
                exp++;
                tt /= x;
            }
            if (exp > 1) cnt *= exp;
            if (tt == 1) break;
        }
    }
    cout << triangle << '\n';
}

int main() {
    solve1();
    solve2();
    return 0;
}