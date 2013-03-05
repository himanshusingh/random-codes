#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[100001];
vector<int> f, b;
int main()
{
  int sum = 0, need;
  cin>>n;
  for (int i = 0; i < n; i++) cin>>a[i], sum += a[i];
  if (sum%3) {
    cout<<"0"<<endl;
  } else {
    need = sum/3;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum == need) f.push_back(i);
    }
    sum = 0;
    for (int i = n-1; i >= 0; i--) {
      sum += a[i];
      if (sum == need) b.push_back(i);
    }

    sort(f.begin(), f.end());
    sort(b.begin(), b.end(), greater<int>());

    int j = 0;
    long long ans = 0;
    for (int i = f.size()-1; i >= 0; i--) {
      while (j < b.size() && b[j] > f[i] + 1) ++j;
      ans += j;
    }
    cout<<ans<<endl;
  }
  return 0;
}
