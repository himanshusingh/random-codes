/* Problem Link: http://www.codeforces.com/problemset/problem/124/C */
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
string str;
int cnt[26];
int parent[1024], size[1024];
int get(int x)
{
  return (parent[x] == x)?parent[x]:parent[x]=get(parent[x]);
}
void unite(int x, int y)
{
  x = get(x), y = get(y);
  if (x == y) return;
  parent[x] = y;
  size[y] += size[x];
}
bool isPrime(int x)
{
  for (int i = 2; i*i <= x; i++) if (x%i == 0) return false;
  return true;
}
char ans[1024];
int main()
{
	cin>>str;
	for (int i = 0; i < str.size(); i++) cnt[str[i]-'a']++;

  int n = str.size();
  for (int i = 1; i <= n; i++) parent[i] = i, size[i] = 1;
  for (int i = 2; i <= n; i++) if (isPrime(i))
    for (int j = i; j <= n; j += i) unite(j, i);

  set< pair<int, int> > divs;

  for (int i = 1; i <= n; i++) divs.insert(make_pair(-size[get(i)], get(i)));

  for (__typeof(divs.begin()) it = divs.begin(); it != divs.end(); it++) {
    int sz = -it->first;
    int par = it->second;
    int mc = 0;
    for (int c = 0; c < 26; c++) if (cnt[c] > cnt[mc]) mc = c;
    if (cnt[mc] < sz) {
      cout<<"NO"<<endl;
      return 0;
    }
    for (int i = 1; i <= n; i++) if (get(i) == par) {
      ans[i] = mc+'a';
      cnt[mc]--;
    }
  }
  cout<<"YES"<<endl;
  for (int i = 1; i <= n; i++) cout<<ans[i];
  cout<<endl;
  return 0;
}