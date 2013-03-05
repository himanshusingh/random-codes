#include<iostream>
using namespace std;
long long pow10[20];
long long compute(long long n)
{
  int len = 0;
  long long t = n;
  int first;
  while (t) { ++len; first = t%10; t /= 10; }
  if (len <= 1) return n;
  long long ans = 9;
  for (int l = 0; l <= len - 3; l++)
    ans += 9*pow10[l];
  ans += (first - 1)*pow10[len-2];
  t = first*pow10[len - 1] + first;
  if (n - t >= 0) 
    ans += ((n - t)/10)%pow10[len-2] + 1;
  return ans;
}
int main()
{
  long long l, r;
  pow10[0] = 1;
  for (int i = 1; i < 20; i++) pow10[i] = 10*pow10[i-1];
  cin>>l>>r;
  cout<<compute(r) - compute(l-1)<<endl;
  return 0;
}
