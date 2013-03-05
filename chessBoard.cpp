#include<iostream>
using namespace std;
const int MAX_N = int(4e6)+7;

int main()
{
  int n, m;
  cin>>n>>m;
  while (n > 1 && m > 1) {
    if (n > m) n = n - m + 1;
    else m = m - n + 1;
  }
  cout<<m+n-1<<endl;
  return 0;
}
