#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    string s; cin >> s;
    stack<string> st;
    for(int i = 0; i < s.size();){
        string t = "";
        while(i < s.size() && isdigit(s[i])){
            t += s[i];
            i++;
        }
        if(!st.empty() && st.top() == "*"){
            st.pop();
            ll a = stoll(st.top());
            ll b = stoll(t);
            st.pop();
            t = to_string(a*b);
        }
        else if(!st.empty() && st.top() == "/"){
            st.pop();
            ll a = stoll(st.top());
            ll b = stoll(t);
            st.pop();
            t = to_string(a/b);
        }
        st.push(t);
        if(i >= s.size()) break;
        st.push(string(1, s[i]));
        i++;
    }
    s = "";
    while(!st.empty()){
        string tmp = st.top();
        reverse(all(tmp));
        s += tmp;
        st.pop();
    }
    reverse(all(s));
    for(int i = 0; i < s.size();){
        string t = "";
        while(i < s.size() && isdigit(s[i])){
            t += s[i];
            i++;
        }
        if(!st.empty() && st.top() == "+"){
            st.pop();
            ll a = stoll(st.top());
            ll b = stoll(t);
            st.pop();
            t = to_string(a+b);
        }
        else if(!st.empty() && st.top() == "-"){
            st.pop();
            ll a = stoll(st.top());
            ll b = stoll(t);
            st.pop();
            t = to_string(a-b);
        }
        st.push(t);
        if(i >= s.size()) break;
        st.push(string(1, s[i]));
        i++; 
    }
    cout << st.top();
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}