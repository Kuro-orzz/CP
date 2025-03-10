#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v;
    int k; cin>>k;
    v.push_back(k);
    for(int i=1; i<n; i++){
        int x; cin>>x;
        if(x<v.back()){
            if(x>1)
                v.push_back(x-1);
            else
                v.push_back(1);
            v.push_back(x);
        }
        else
            v.push_back(x);
    }
    cout<<v.size()<<endl;
    for(int x:v)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}