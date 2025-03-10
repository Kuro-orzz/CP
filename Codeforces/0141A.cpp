#include <iostream>
#include <map>
using namespace std;

void solve(){
    string s1, s2, s;
    cin >> s1 >> s2 >> s;
    map<char,int> mp;
    for(int i=0; i<s1.length(); i++)
        mp[s1[i]]++;
    for(int i=0; i<s2.length(); i++)
        mp[s2[i]]++;

    for(int i=0; i<s.length(); i++){
        if(mp[s[i]] > 0){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
        }
        else{
            cout<< "NO";
            return;
        }
    }

    if(mp.empty())
        cout<< "YES";
    else
        cout<< "NO";
}

int main()
{
    //freopen("file.inp.c","r",stdin);
    solve();
    return 0;
}