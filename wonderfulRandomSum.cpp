#include<iostream>
using namespace std;
const int oo = 2000000000;
int seq[100001];
int f[100002][2], b[100002][2];
int mf[100001], mb[100001];
int main()
{
  int n;
  cin>>n;
  int ans = -oo;
  for (int i = 1; i <= n; i++)
    cin>>seq[i];
  for (int i = 1; i <= n; i++) {
    f[i][0] = seq[i] + max(f[i-1][1], f[i - 1][0]);
    f[i][1] = -seq[i] + f[i-1][1];
    mf[i] = max(f[i][0], f[i][1]);
  }
  for (int i = n; i >= 1; i--) {
    b[i][0] = seq[i] + max(b[i+1][0], b[i+1][1]);
    b[i][1] = -seq[i] + b[i+1][1];
    mb[i] = max(b[i][0], b[i][1]);
  }
 
  for (int i = 0; i <= n; i++)
    ans  = max(ans, mf[i] + mb[i+1]);
  cout<<ans<<endl;

  return 0;
}
