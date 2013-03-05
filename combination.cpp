#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
  int n;
  vector < pair<int, int> > cards;
  cin>>n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin>>a>>b;
    cards.push_back(make_pair(b, a));
  }
  sort (cards.begin(), cards.end());
  int ans = 0;
  int c = 1;
  for (int i = n - 1; i >= 0; i--) {
    ans += cards[i].second;
    c += cards[i].first - 1;
    if (!c) break;
  }
  cout<<ans<<endl;
}
