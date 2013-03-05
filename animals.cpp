#include<fstream>
#include<cstring>
using namespace std;
const char iname[]="input.txt";
const char oname[]="output.txt";
ifstream in(iname);
ofstream out(oname);  
int memo[101][10001];
int c[101];
int n;
int solve(int i, int x)
{
  if (i == 0) return 0;
  int &ret = memo[i][x];
  if (~ret) return ret;
  ret = 0;
  if (x-(n-i+1)*c[i] >= 0)
    ret = max(ret, solve(i-1, x-(n-i+1)*c[i]) + 1);
  ret = max(ret, solve(i-1,x));
  return ret;    
}
int main()
{
  memset(memo, -1, sizeof(memo));
  int x;
  in>>n>>x;
  for (int i = 1; i <= n; i++) in>>c[i];
  out<<solve(n, x)<<endl;
  return 0;
}
