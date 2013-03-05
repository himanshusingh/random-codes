#include<iostream>
#include<cstdio>
using namespace std;
typedef pair<int,int> pii;
const int MAX_N = 501*2510;
int parent[MAX_N];
int sources[MAX_N];
int applied[511][2510];
int find_set(int x)
{
  return (x==parent[x])?x:(parent[x]=find_set(parent[x]));
}
void combine(int x, int y)
{
  x = find_set(x);
  y = find_set(y);
  if (x == y) return;
  parent[x] = y;
  sources[y] += sources[x];
}
char command[50];
void decode2(int &x1, int &y1, int &x2, int &y2)
{
  int ar[4];
  for (int j = 0, i = 1; i <= 8; i += 2, j++) {
    int a, b;
    if (command[i] <= 'Z' && command[i] >= 'A') a = command[i] -'A';
    if (command[i+1] <= 'Z' && command[i+1] >= 'A') b = command[i+1] - 'A';
    if (command[i] <= 'z' && command[i] >= 'a') a = command[i] - 'a'+26;
    if (command[i+1] <= 'z' && command[i+1] >= 'a') b = command[i+1] - 'a'+26;
    ar[j] = 52*a + b;
  }
  x1 = ar[0], y1 = ar[1], x2 = ar[2], y2 = ar[3];
}
void decode1(int &x1, int &y1)
{
  int ar[2];
  for (int j = 0, i = 1; i <= 4; i += 2, j++) {
    int a, b;
    if (command[i] <= 'Z' && command[i] >= 'A') a = command[i] -'A';
    if (command[i+1] <= 'Z' && command[i+1] >= 'A') b = command[i+1] - 'A';
    if (command[i] <= 'z' && command[i] >= 'a') a = command[i] - 'a'+26;
    if (command[i+1] <= 'z' && command[i+1] >= 'a') b = command[i+1] - 'a'+26;
    ar[j] = 52*a + b;
  }
  x1 = ar[0], y1 = ar[1];
}
int main()
{
  int n, r, c;
  scanf ("%d %d %d", &n, &r, &c);
  for (int i = 0; i < MAX_N; i++) parent[i] = i;
  while (n--) {
    scanf ("%s", command);
    char q = command[0];
    int x1, y1, x2, y2;
    if (q == 'W') {
      decode2(y1,x1,y2,x2);
      int a = ((x1+4)/5)*c+y1, b = ((x2+4)/5)*c+y2;
      combine(a,b);
    } else if (q == 'V') {
      decode1(y1,x1);
      applied[(x1+4)/5][y1]++;
      int a = ((x1+4)/5)*c+y1;
      sources[find_set(a)]++;
    } else if (q == 'R') {
      decode1(y1,x1);
      if (!applied[(x1+4)/5][y1]) continue;
      applied[(x1+4)/5][y1]--;
      int a = ((x1+4)/5)*c+y1;
      a = find_set(a);
      sources[a] = max(0,sources[a]-1);
    } else {
      decode2(y1,x1,y2,x2);
      int a = ((x1+4)/5)*c+y1, b = ((x2+4)/5)*c+y2;
      a = find_set(a);
      b = find_set(b);
      if ((!sources[a] || !sources[b]) && (sources[a]+sources[b]))
	printf ("ON\n");
      else
	printf ("OFF\n");
    }
  }
  return 0;
}
