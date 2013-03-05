#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int dp[2048][2048];
int main()
{
  string from, to;
  cin>>from;
  cin>>to;
  int maxMatch = 0;
  for (int i = 0; i < from.size(); i++)
    for (int j = 0; j < to.size(); j++)
      maxMatch = max(maxMatch, dp[i + 1][j + 1] = (from[i]==to[j]) + dp[i][j]);
  cout<<to.size() - maxMatch<<endl;
  return 0;
}
