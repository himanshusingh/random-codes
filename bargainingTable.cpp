#include<iostream>
#include<string>
using namespace std;
int dp[30][30];
int n, m;
int maxRectangle(int heights[], int n)
{
  heights[n+1] = heights[0] = 0;
  int ans = 0;
  static int stack[30];
  int top = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (heights[i] > heights[stack[top]]) stack[++top] = i;
    else if (heights[i] < heights[stack[top]]) {
    while (top && heights[stack[top - 1]] > heights[i]) {
      ans = max(ans, 2*(heights[stack[top]] + i - stack[top]));
      top--;
    }
    if (heights[stack[top]] > heights[i]) {
      ans = max(ans, 2*(heights[stack[top]] + i - stack[top]));
      heights[stack[top]] = heights[i];
    }
    }
  }
  return ans;
}
int main()
{
  cin>>n>>m;
  char c;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      cin>>c;
      dp[i][j] = !(c - '0');
      if(dp[i][j]) dp[i][j] += dp[i-1][j];
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, maxRectangle(dp[i], m));
  cout<<ans<<endl;
  return 0;
}
