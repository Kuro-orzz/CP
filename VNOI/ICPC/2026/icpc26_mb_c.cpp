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

// Op 1: a[i] * 2 + 1
// Op 2: a[i] / 2
// Thao tác 1 sẽ là thêm bit 1 ở cuối (vd: 0010 -> 00101)
// Thao tác 2 sẽ là bỏ cắt bớt 1 bit ở cuối (vd: 0010 -> 001)

// Do đó 1 số không thể biến thành số bất kì, mà chỉ reach được 1 số lượng số nhất định mà các thao tác thêm, bớt bit khả thi
// Trường hợp nếu a[i] -> Op1 -> Op2 thì sẽ trở về a[i] ban đầu
// -> Vì vậy toàn bộ số thao tác Op2 bắt buộc phải đứng trước Op1, mà số lượng Op2 có thể thay đổi a[i] chỉ là log(a[i]), sau đó ta sẽ sử dụng thao tác 1 tối đa log(2e5)
// -> Ta có thể thấy với a[i] chẵn thì bit cuối sẽ là 0, nếu apply Op1 rồi đến Op2 thì sẽ là thay bit cuối thành 1, nếu cứ tiếp tục thì sẽ thêm bit 1 vào cuối
// -> Nếu a[i] chẵn -> Op1 -> Op2 (log(2e5) lần) thì các số biến đổi được sau đó sẽ không trùng với bất kì số nào trước đó 
// -> Tổng số lượng số có thể tới được là log(2e5)^2
// -> Với mỗi số nó có thể reach log(2e5)^2 số khác <=2e5, nhưng do có đặc điểm hội tụ về 0 nếu apply Op2 đủ nhiều nên chắc chắn các số có thể gặp nhau -> không tồn tại trường hợp có số không thể biến đổi về giống nhau

// Complexity: O(n log(2e5)^2)
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // cnt[i]: number of element in a[] can reach i
    // cost[i]: minimum total cost to reach i
    vector<int> cnt(2e5+1, 0), cost(2e5+1, 0);
    for (int i = 0; i < n; i++) {
        int op2 = 0;
        do {
            int x = a[i], op1 = 0;
            while (x <= 2e5) {
                cnt[x]++;
                cost[x] += op1 + op2;
                x = x * 2 + 1;
                op1++;
            }
            // odd -> skip duplicate
            while (a[i] && a[i] % 2) {
                a[i] /= 2;
                op2++;
                cnt[a[i]]++;
                cost[a[i]] += op2;
            }
            a[i] /= 2;
            op2++;
        } while (a[i]);
    }

    int ans = cost[0], cur = 0;
    for (int i = 1; i <= 2e5; i++) {
        if (cnt[i] == n && cost[i] < ans) {
            ans = cost[i];
            cur = i;
        }
    }
    cout << ans;
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
