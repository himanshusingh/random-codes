#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 1e5+7;
ll seq[MAX_N];
map<ll, int> seen;
int cnt[MAX_N];
int main()
{
  int n;
  ll k;
  cin>>n>>k;
  for (int i = 1; i <= n; i++) cin>>seq[i];
  sort(seq+1, seq+n+1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i] = 1;
    if ((seq[i]%k == 0) && (seen.find(seq[i]/k) != seen.end())) {
      cnt[i] = cnt[seen[seq[i]/k]] + 1;
      cnt[seen[seq[i]/k]] = 0;
    }
    seen[seq[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (cnt[i] > 1) ans += (cnt[i]+1)/2;
    else ans += cnt[i];
  cout<<ans<<endl;
  return 0;
}
