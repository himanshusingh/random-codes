#include <iostream>
#include <string>
using namespace std;
long long dp[2048], psum[2048];
bool pali[2048][2048];
string input;
void preprocess()
{
  int len = input.size();
  for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) pali[i][j] = false;
  for (int i = 0; i < len; i++) pali[i][i] = true;

  for (int l = 2; l <= len; l++) {
    for (int i = 0; i + l <= len; i++) {
      int j = i + l - 1;
      if (l != 2)
	pali[i][j] = (input[i]==input[j])&&(pali[i+1][j-1]);
      else
	pali[i][j] = (input[i]==input[j]);
    }
  }
  psum[0] = 1;
  for (int i = 1; i < len; i++) {
    psum[i] = psum[i-1];
    for (int j = 0; j <= i; j++) {
      psum[i] += pali[j][i];
    }
  }
}

int main()
{
  cin>>input;
  preprocess();
  int len = input.size();
  dp[0] = 0;
  for (int i = 1; i < len; i++) {
    dp[i] = dp[i-1];
    for (int j = i; j > 0; j--)
      dp[i] += psum[j-1]*pali[j][i];
  }
  cout<<dp[len - 1]<<endl;
  return 0;
}
				   
