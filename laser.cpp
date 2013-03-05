#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll overlap(ll a, ll b, ll x, ll y)
{
  long long ret = max(0ll, min(y,b)-max(x,a)+1);
  return ret;
}

int main()
{
  int t;
  cin>>t;
  while (t--) {
    long long n, m, x1,x2,y1,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    long long l, r, u, d;
    l = min(x1-1, x2-1);
    r = min(n-x1,n-x2);
    u = min(y1-1,y2-1);
    d = min(m-y1,m-y2);
    long long ox = overlap(x1-l,x1+r, x2-l,x2+r);
    long long oy = overlap(y1-u,y1+d, y2-u,y2+d);
    long long ans = n*m - 2*(l+r+1)*(u+d+1) + ox*oy;
    cout<<ans<<endl;
  }
  return 0;
}
