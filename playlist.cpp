#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct track
{
  int l;
  double p;
  track(int _l, double _p): l(_l), p(_p) {}
  bool operator<(const track& b) const
  {
    return l*1.0*p/(1-p) > b.l*1.0*b.p/(1-b.p);
  }
};
vector< track > list;
int main()
{
  int n;
  cin>>n;
  for (int i = 0; i < n; i++) {
    int l;
    double p;
    cin>>l>>p; p /= 100.0;
    list.push_back(track(l,p));
  }
  sort(list.begin(), list.end());
  double ans = 0, expLen;
  for (int i = 0; i < n; i++) {
    ans += list[i].l;
    ans += expLen*(1-list[i].p);
    expLen += list[i].l*list[i].p;
  }
  printf ("%0.6lf\n", ans);
  return 0;
}
