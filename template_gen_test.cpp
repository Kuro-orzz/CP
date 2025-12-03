#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

mt19937 rng(time(0));

void sinh() {
    ofstream gen(TASK ".inp");

}

vector<int> solve1() {
    vector<int> ans;
    // Put your optimize solution here.
    return ans;
}


vector<int> solve2() {
    vector<int> ans;
    // Put your bruteforce solution here.
    return ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    for (int i = 0; i < 100; i++) {
        sinh();

        freopen(TASK ".inp", "r", stdin);
        vector<int> a = solve1();
        fclose(stdin);
        
        freopen(TASK ".inp", "r", stdin);
        vector<int> b = solve2();
        fclose(stdin);

        ofstream out(TASK ".out");
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                out << "WRONG TEST CASE";
                return 0;
            }
        }
        out << "AC";
    }

    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}