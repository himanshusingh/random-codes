#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string t, s, e;
int Zs[4040], Ze[4040];

long long hash[4040];
long long ppow[4040];
void zline(string &t, string &p, int Z[])
{
  string m = p + '#' + t;
  int n = m.size();
  for (int l = 0, r = 0, i = 1; i < n; i++) {
    if (i <= r)
      Z[i] = min(r - i + 1, Z[i - l]);
    while (i + Z[i] < n && m[Z[i]] == m[i + Z[i]]) ++Z[i];
    if (i + Z[i] - 1 > r)
      l = i, r = i + Z[i] - 1;
  }
  for (int i = p.size() + 1; i < n; i++)
    Z[i-p.size()-1] = Z[i];
}
vector<long long> hashes;
int main()
{
  cin>>t>>s>>e;
  zline(t, s, Zs);
  zline(t, e, Ze);
  ppow[0] = 1;
  int n = t.size(), sn = s.size(), en = e.size();
  int mn = max(sn, en);
  for (int i = 1; i <= 2020; i++) ppow[i] = 31*ppow[i-1];
  for (int i = 0; i < n; i++) hash[i] = ppow[i]*(t[i]-'a' + 1) + (i?hash[i-1]:0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + mn - 1 ; j < n; j++) {
      if (Zs[i] == sn && Ze[j-en+1] == en) {
	long long h = (hash[j] - (i?hash[i-1]:0))*ppow[n-i];
	hashes.push_back(h);
      }
    }
  sort (hashes.begin(), hashes.end());
  cout<<unique(hashes.begin(), hashes.end()) - hashes.begin()<<endl;
  return 0;
}
