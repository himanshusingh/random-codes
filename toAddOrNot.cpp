#include<iostream>
#include<algorithm>
using namespace std;
long long seq[100001], n, pre[100001], k;
int main()
{
  cin>>n>>k;
  for (int i = 0; i < n; i++) cin>>seq[i];
  sort(seq, seq+n);
  int ans = seq[0], rep = 1;
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i-1] + seq[i-1];
    int lo = 0,hi = i;
    int guess = 0;
    while (lo <= hi) {
      int mi = (lo+hi)/2;
      if (mi*seq[i] <= pre[i]-pre[i-mi] + k) guess = mi, lo = mi+1;
      else hi = mi-1;
    }
    if (guess+1 > rep) rep = guess+1, ans = seq[i];
  }
  cout<<rep<<" "<<ans<<endl;
  return 0;
}
