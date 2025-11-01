#include <bits/stdc++.h>
using namespace std;

void bruteforce() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum << '\n';
}

void inclusion_exclusion() {
    int div3 = 999/3;
    int div5 = 999/5;
    int div35 = 999/3/5;
    int sumDiv3 = div3 * (3 + div3 * 3) / 2;
    int sumDiv5 = div5 * (5 + div5 * 5) / 2;
    int sumDiv35 = div35 * (15 + div35 * 15) / 2;
    cout << sumDiv3 + sumDiv5 - sumDiv35 << '\n';
}

int main() {
    bruteforce();
    inclusion_exclusion();
    return 0;
}