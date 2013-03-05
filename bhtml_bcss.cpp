#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<list>
using namespace std;
const int MAX_N = 1e6+7;
struct HTML
{
  string tag;
  vector<HTML> child;
}root;
char html[MAX_N], tmp[2012], *s = html;
HTML dfs(const string& tag)
{
  HTML ele;
  ele.tag = tag;
  while (*s && s[1] != '/') {
    string ctag;
    while (*++s != '>' && *s != '/') ctag += *s;
    if (*s++ == '/') {
      ++s;
      HTML child;
      child.tag = ctag;
      ele.child.push_back(child);
    } else {
      ele.child.push_back(dfs(ctag));
    }
  }
  if (*s && s[1] == '/') while (*s++ != '>');
  return ele;
}
int solve(HTML &node, vector<string>& q, int n)
{
  int ret = 0;
  if (node.tag == q[n]) {
    if (n + 1 == q.size()) ret++;
    else n++;
  }
  for (int i = 0; i < node.child.size(); i++)
    ret += solve(node.child[i], q, n);
  return ret;
}
int main()
{
  gets(html);
  root = dfs("");
  int n;
  sscanf(gets(tmp), "%d", &n);
  for (int i = 0; i < n; i++) {
    vector<string> q;
    for (char *v = strtok(gets(tmp)," "); v; v = strtok(0, " ")) q.push_back(v);
    int ans = solve(root, q, 0);
    printf ("%d\n", ans);
  }
  return 0;
}
