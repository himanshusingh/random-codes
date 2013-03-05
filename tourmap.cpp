#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<cstdlib>
using namespace std;
char t1[100],t2[100],t3[100];
int main()
{
  int tests;
  scanf ("%d", &tests);
  while (tests--) {
    int n;
    scanf ("%d", &n);
    map<string, int> in;
    map<string, string > next;
    map< pair<string, string>, int > ticket;
    set<string> cities;
    int cost = 0;
    for (int i = 1; i <= n-1; i++) {
      string a, b, c;
      scanf ("%s %s %s", t1, t2, t3);
      a = t1, b = t2, c = t3;
      in[b]++;
      cities.insert(a);
      cities.insert(b);
      t3[strlen(t3)-1] = '\0';
      int p = atoi(t3);
      cost += p;
      next[a] = b;
      ticket[make_pair(a,b)] = p;
    }
    string first;
    for (typeof(cities.begin()) it = cities.begin(); it != cities.end(); it++) {
      if (in.find(*it) == in.end()) { first = *it; break; }
    }
    while (next.find(first) != next.end()) {
      string to = next[first];
      printf ("%s %s %d$\n", first.c_str(), to.c_str(), ticket[make_pair(first, to)]);
      first = to;
    }
    printf ("%d$\n", cost);
  }
  return 0;
}
