#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int binarysearch(int arr[], int left, int right, int x) {
  int mid;
  while (right >= left) {
    mid = left + (right - left) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      right = mid - 1;
    if (arr[mid] < x)
      left = mid + 1;
  }
  return -1;
}

int main() {
  freopen("friend.inp", "r", stdin);
  freopen("friend.out", "w", stdout);
  int n;
  cin >> n;
  int t;
  cin >> t;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    mp[k]++;
  }
  int a[100000];
  int b[100000];
  int j = 0;
  for (auto it : mp) {
    a[j] = it.first;
    b[j] = it.second;
    j++;
  }
  sort(a, a + j);
  int res = 0;
  
  for (int i = 0; i < j; i++) {
    if (t % 2 ==0)
      {if (a[i] >= t / 2) break;}
    else if (a[i] > t / 2) break;
    int y = binarysearch(a, i, j, t - a[i]);
    if (y != -1)
      res += b[i] * b[y];
  }

  if (t % 2 == 0)
    if (binarysearch(a, 0, j, t / 2) != -1)
      res += b[binarysearch(a, 0, j, t / 2)] * (b[binarysearch(a, 0, j, t/2)]-1) / 2;
  if (binarysearch(a, 0, j, t) != -1)
    res += b[binarysearch(a, 0, j, t)];
  cout << res;
  return 0;
}
