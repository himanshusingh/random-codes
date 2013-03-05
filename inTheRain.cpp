#include <iostream>
using namespace std;
int a[1024];
bool ok[1024];
bool dp[1024];
int main ()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++)
    cin>>a[i];
  int days = 1;
  for (; days <= 1000; days++) {
    for (int i = 1; i <= n; i++) 
      if (a[i] < days) ok[i] = false;
      else ok[i] = true;
    if ((ok[1] == false) || (ok[n] == false)) break;
    dp[1] = true;
    for (int i = 2; i <= n; i++) dp[i] = false;
    for (int i = 1; i <= n - 1; i++) {
      dp[i + 1] |= dp[i]&&ok[i+1];
      dp[i + 2] |= dp[i]&&ok[i+2];
    }
    if (!dp[n]) break;
  }
  cout<<days-1<<endl;
  return 0;
}
