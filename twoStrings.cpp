#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 2e5+7;
int f[MAX_N], b[MAX_N], fp[MAX_N], bp[MAX_N];;
vector<int> p[26], pr[26];
char s[MAX_N], t[MAX_N];
int binary_search(vector<int>& p, int x)
{
  int lo = 0, hi = p.size()-1;
  int ret = 0;
  while (lo <= hi) {
    int mi = (lo + hi)/2;
      if (p[mi] <= x) ret = p[mi], lo = mi + 1;
      else hi = mi - 1;
  }
  return ret;
}
int main()
{
  cin>>s+1>>t+1;
  int nt = 0, ns = 0;
  for (int i = 1; t[i]; i++, nt++) p[t[i]-'a'].push_back(i);
  for (int i = nt; i >= 1; i--) pr[t[i]-'a'].push_back(nt-i+1);
  for (int i = 1; s[i]; i++, ns++) {
    fp[i] = binary_search(p[s[i]-'a'], f[i-1] + 1);
    f[i] = max(fp[i], f[i-1]);

  }
  for (int i = ns; i >= 1; i--) {
    bp[i] = binary_search(pr[s[i]-'a'], b[i+1]+1);
    b[i] = max(bp[i], b[i+1]);

  }
  bool ans = true;
  for (int i = 1; i <= ns; i++) {
    if ((fp[i] && fp[i] + b[i+1] >= nt) || (bp[i] && bp[i] + f[i-1] >= nt)) {}
    else ans = false;
  }
  if (ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
