#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 1e5+7;
int seq[MAX_N], ss[MAX_N];
int main()
{
  int n;
  cin>>n;
  for (int i = 0; i < n; i++) cin>>seq[i], ss[i] = seq[i];
  sort(ss, ss+n);
  int mis = 0;
  for (int i = 0; i < n; i++) mis += ss[i] != seq[i];
  if (mis > 2)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
  return 0;
}
