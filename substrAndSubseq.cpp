#include<iostream>
#include<string>
using namespace std;
const int mod = 1e9 + 7;
int dp[5001][5001];
int main()
{
  string s, t;
  cin>>s;
  cin>>t;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < t.size(); j++)
      dp[i + 1][j + 1] = (dp[i+1][j] + (s[i] == t[j])*(dp[i][j]+1))%mod;
  int ans = 0;
  for (int i = 1; i <= s.size(); i++)
    ans = (ans + dp[i][t.size()o])%mod;
  cout<<ans<<endl;
  
  return 0;
}
