#include<iostream>
#include<cmath>
using namespace std;
#define B(i) (1<<(i))
double dp[1<<25];
int p[1<<25];
struct object
{
  int x, y;
}ob[25];
double dist[25][25];
int n;
void printResults(int bitmask)
{
  if (!bitmask) {cout<<"0 "; return;}
  printResults(p[bitmask]);
  for (int i = 0; i < n; i++) if ((p[bitmask]^bitmask) & B(i)) {
      cout<<i+1<<" ";
    }
  cout<<"0 ";
}

int main()
{
  cin>>ob[0].x>>ob[0].y;
  cin>>n;
  for (int i = 1; i <= n; i++)
    cin>>ob[i].x>>ob[i].y;
  for (int i = 0; i < B(n); i++) dp[i] = 1000000000000ll;
  
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) 
      dist[i][j] = ((ob[i].x-ob[j].x)*(ob[i].x-ob[j].x) + (ob[i].y - ob[j].y)*(ob[i].y - ob[j].y));
  
  dp[0] = 0;
  for (int b = 1; b < B(n); b++) {
    int i = b&-b;
    for (i = 0; i < n; i++) if (b & B(i)) break;
    int j = i;
    if (dp[b] > dp[b^B(i)] + dist[0][i+1]+dist[i+1][j+1]+dist[j+1][0]) {
      dp[b] = dp[b^B(i)] + dist[0][i+1]+dist[i+1][j+1]+dist[j+1][0];
      p[b] = b^B(i);
    }
    for (j = 0; j < n; j++) if ((b & B(j)) && j != i) {
	if (dp[b] > dp[b^B(i)^B(j)] + dist[0][i+1]+dist[i+1][j+1]+dist[j+1][0]) {
	  dp[b] = dp[b^B(i)^B(j)] + dist[0][i+1]+dist[i+1][j+1]+dist[j+1][0];
	  p[b] = b^B(i)^B(j);
	}
      }
  }
  cout<<dp[B(n) -1]<<endl;
  printResults(B(n)-1);
  cout<<endl;
  return 0;
}
