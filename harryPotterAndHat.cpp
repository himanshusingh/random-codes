#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
string str;
vector<bool> ans(4,0);
char mp[256];
map< vector<int>, bool > seen;
string house[] = {"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};
void dfs(vector<int>& x, int n)
{
  int mn = 1000000;
  for (int i = 0; i < 4; i++) if (x[i] < mn) mn = x[i];
  if (n == str.size()) {
    for (int i = 0; i < 4; i++) if (x[i] == mn) ans[i] = true;
    return;
  }
  if (seen[x]) return;
  seen[x] = true;
  if (str[n] == '?') {
    for (int i = 0; i < 4; i++) if (x[i] == mn) {
	x[i]++;
	dfs(x, n+1);
	x[i]--;
      }
  } else {
    x[mp[str[n]]]++;
    dfs(x, n+1);
    x[mp[str[n]]]--;
  }
}
int main()
{
  mp['G'] = 0, mp['H'] = 1, mp['R'] = 2, mp['S'] = 3;
  int n;
  cin>>n;
  cin>>str;
  vector<int> x(4,0);
  dfs(x, 0);
  for (int i = 0; i < 4; i++) if (ans[i]) cout<<house[i]<<endl;
  return 0;
}
