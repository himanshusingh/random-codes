#include<iostream>
#include<set>
using namespace std;
const int MAX_N = 1e5+7;
int a[MAX_N], b[MAX_N];
int pos[MAX_N];
int ans[MAX_N];
set<int> ng, pv;
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i], pos[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    cin>>b[i];
    int d = pos[b[i]] - i;
    if (d < 0) ng.insert(-d);
    else pv.insert(d);
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = min(*ng.begin(), *pv.begin());
    int k = *ng.rbegin() + i;
    if (k >= n) ng.erase(ng.rbegin()), pv.insert(0);
    k = *pv.begin() - 1;
    if (k < 0) pv.erase(pv.begin()), ng.insert(1);
  }
  for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";cout<<endl;
  return 0;
}
