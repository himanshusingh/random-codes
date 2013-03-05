#include<iostream>
#include<string>
using namespace std;

int main()
{
  string seq;
  cin>>seq;
  int stack[1000001], top = 0;
  int longest = 0, cnt = 0;
  stack[0] = -1;
  for (int i = 0; i < seq.size(); i++) {
    if (seq[i] == '(') {
      stack[++top] = 1;
      continue;
    }
    int c = 1;
    while (top) {
    }
  }
  return 0;
  }
