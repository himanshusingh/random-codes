#include<iostream>
#include<cmath>
using namespace std;
long long val(long long y)
{
  long long s = 0;
  while (y) s += y%10, y/=10;
  return s;
}
int main()
{
  long long n;
  while (cin>>n) {
  long long ans = 1e10;
  for (long long sum = 1; sum <= 9*9; sum++) {
    long long d = sum*sum + 4*n;
    if ((long long)sqrt(d)*(long long)sqrt(d) != d) continue;
    long long x = (-1*sum + (long long)sqrt(d))/2;
    if (val(x) == sum) ans = min(ans, x);
  }
  if (ans != 1e10 && (sqrt(n) - 100 > ans)) 
    cout<<ans<<" "<<n<<" "<<sqrt(n)-100<<endl;
  }
  return 0;
}
