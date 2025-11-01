#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPalindrome(int x) {
    string s = to_string(x);
    int i = 0, j = (int)s.size()-1;
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int main() {
    int res = 0;
    for (int i = 100; i <= 999; i++)
        for (int j = i+1; j <= 999; j++) {
            if (isPalindrome(i*j))
                res = max(res, i*j);
        }
    cout << res;
    return 0;
}