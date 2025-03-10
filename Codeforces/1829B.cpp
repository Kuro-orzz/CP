#include <iostream>
#include <vector>
using namespace std;
int main(){
	//freopen("nguyen.inp","r",stdin);
	int t;cin>>t;
	vector <int> v;
	
	while (t--){
		int n;cin>>n;
		int a[n];
		for (int i = 0;i<n;i++) cin>>a[i];
		for (int i =0;i<n;i++){
			if (a[i] == 0){
				int dem = 0;
				for (int j=i;j<n;j++){
					if (a[j]==0){
						dem++;
					v.push_back(dem);}
					else break;
				}
			}
		}
		int maxi = 0;
		for (int x : v){
			if (x > maxi) {
				maxi = x;
			}
		}
		cout<<maxi<<"\n";
		v.erase(v.begin(),v.end());
	}
	return 0;
}