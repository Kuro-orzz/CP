#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        unordered_set<char> st;
        int n; cin >> n;
        string s; cin >> s;
        int res = 0;
        for(char i : s){
            st.insert(i);
            res += st.size();
        }
        cout << res << endl;
    }
    return 0;
}