#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int oo = 100000000;
pair<char, int> path[101][101][11], bestPath[101][101][11];
int dp[101][101][11];
int bestStart, bestSum, bestEnd;
char G[101][101];
int n, m, k;

int main()
{
  cin>>n>>m>>k;
  for (int i = n; i >= 1; i--)
    cin>>G[i] + 1;
  bestSum = -1;
  for (int i = 1; i <= m; i++) {
    memset(dp, -1, sizeof(dp));
    dp[1][i][(G[1][i]-'0')%(k+1)] = G[1][i]-'0';

    for (int y = 2; y <= n; y++)
      for (int x = 1; x <= m; x++) 
	for (int mod = 0; mod <= k; mod++) {
	  int mm = (mod+G[y][x]-'0')%(k+1);
	  if ((x-1 >= 1) && (~dp[y-1][x-1][mod]) && (dp[y-1][x-1][mod] + G[y][x]-'0' > dp[y][x][mm])) {
	    dp[y][x][mm] = dp[y-1][x-1][mod] + G[y][x] - '0';
	    path[y][x][mm] = make_pair('R', mod);
	  }

	  if ((x+1 <= m) && (~dp[y-1][x+1][mod]) && (dp[y-1][x+1][mod] + G[y][x] - '0'> dp[y][x][mm])) {
	    dp[y][x][mm] = dp[y-1][x+1][mod] + G[y][x] - '0';
	    path[y][x][mm] = make_pair('L', mod);
	  }
	}
    for (int x = 1; x <= m; x++) if (dp[n][x][0] > bestSum) {
	bestSum = dp[n][x][0];
	bestEnd = x;
	bestStart = i;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int mm = 0; mm <= k; mm++) bestPath[i][j][mm] = path[i][j][mm];
      }
  }
  cout<<bestSum<<endl;
  if (bestSum != -1) {
    cout<<bestStart<<endl;
    int x = bestEnd, y = n, mod = 0;
    string p;
    for (int i = 1; i < n; i++) {
      p += bestPath[y][x][mod].first;
      if (bestPath[y][x][mod].first == 'R') mod = bestPath[y][x][mod].second, x--;
      else mod = bestPath[y][x][mod].second, x++;
      y--;
    }
    for (int i = p.size()-1; i >= 0; i--) cout<<p[i];
    cout<<endl;
  }
  return 0;
}
