#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int MAX_N = 1e5+7;
int first[MAX_N], next[MAX_N], last[MAX_N], cnt[MAX_N], ff[MAX_N];
int BIT[MAX_N];
void update(int x, int v)
{
  for (;x <= MAX_N; x += (x&-x)) BIT[x] += v;
}
int read(int x)
{
  int ret = 0;
  for (;x;x-=(x&-x)) ret += BIT[x];
  return ret;
}
vector< pair<int,int> > Q[MAX_N];
int seq[MAX_N], ss[MAX_N];
int ans[MAX_N];
int main()
{
  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++) cin>>seq[i];
  for (int i = 1; i <= m; i++) {
    int b, e;
    cin>>b>>e;
    Q[e].push_back(make_pair(b,i));
  }
  for (int i = 1; i <= n; i++) {
    int x = seq[i];
    if (x >= MAX_N) continue;
    cnt[x]++;
    next[last[x]] = i;
    last[x] = i;
    if (cnt[x] == 1) first[x] = i;
    if (cnt[x] == x) {
      update(first[x], 1);
    } else if (cnt[x] == x+1) {
      update(first[x], -2);
      ff[x] = first[x];
      first[x] = next[first[x]];
      update(first[x], 1);
    } else if (cnt[x] > x+1) {
      update(ff[x], 1);
      ff[x] = first[x];
      update(first[x], -2);
      first[x] = next[first[x]];
      update(first[x], 1);
    }
    for (int j = 0; j < Q[i].size(); j++) {
      int q = Q[i][j].second;
      int b = Q[i][j].first, e = i;
      ans[q] = read(e) - read(b-1);
    }
  }
  for (int i = 1; i <= m; i++) cout<<ans[i]<<endl;
  return 0;
}
