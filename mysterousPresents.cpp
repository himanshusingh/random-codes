#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define mp make_pair
#define xx first.first
#define xy first.second
#define y second

vector< pair< pair<int, int>, int > > env;
int dp[1000001];
void print(int pos)
{
  for (int i = pos - 1; i >= 0; i--)
    if ((dp[i] + 1 == dp[pos]) && (env[i].xx < env[pos].xx && env[i].xy < env[pos].xy)) {
      print(i);
      break;
    }
  cout<<env[pos].y<<" ";
}
int main()
{
  int n, width, height;
  cin>>n>>width>>height;
  for (int i = 1; i <= n; i++) {
    int w, h;
    cin>>w>>h;
    if (w > width && h > height)
      env.push_back(mp(mp(w,h),i));
  }
  sort(env.begin(), env.end());
  for (int i = 0; i < env.size(); i++) dp[i] = 1;

  for (int i = 0; i < env.size(); i++)
    for (int j = i-1; j >= 0; j--) 
      if ((env[j].xx < env[i].xx) && (env[j].xy < env[i].xy)) {
	dp[i] = max(dp[i], dp[j] + 1);
      }
  int mx, pos;
  mx = 1;
  for (int i = 0; i < env.size(); i++) if (dp[i] >= mx) pos = i, mx = dp[i];
  if (env.size()) {
    cout<<dp[pos]<<endl;
    print(pos);
    cout<<endl;
  } else cout<<"0"<<endl;

  return 0;
}
