#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> disc, price;

int main()
{
  int n, m;
  cin>>m;
  for (int i = 0; i < m; i++) {
    int d;
    cin>>d;
    disc.push_back(d);
  }
  cin>>n;
  for (int i = 0; i < n; i++) {
    int p;
    cin>>p;
    price.push_back(p);
  }
  sort(disc.begin(), disc.end());
  sort(price.rbegin(), price.rend());
  int ans = 0, cnt = 0, pp = 0;
  for (int i = 0; i < price.size(); i++) {
    pp += price[i];
    cnt++;
    if (cnt == disc[0]) {
      cnt = 0;
      ans += pp;
      i += 2;
      pp = 0;
    }
  }
  ans += pp;
  cout<<ans<<endl;
  return 0;
}
