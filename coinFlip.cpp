#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int tests;
  scanf ("%d", &tests);
  while (tests--) {
    int G;
    scanf ("%d", &G);
    while (G--) {
      int I, N, Q;
      scanf ("%d %d %d", &I, &N, &Q);
      int head, tail;
      if (I == 1) head = N/2, tail = N-head;
      else tail = N/2, head = N-tail;
      if (Q == 1) printf ("%d\n", head);
      else printf ("%d\n", tail);
    }
  }
  return 0;
}
