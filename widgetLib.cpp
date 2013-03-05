#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;
struct widget
{
  long long x, y;
  int s, b;
  int type;
  vector<string> child;
  widget(int _type, long long _x = 0, long long _y = 0) : type(_type),x(_x),y(_y),s(0),b(0) {}
  widget() {}
};
map<string, widget> ntow;
void dfs(widget& w)
{
  if (w.type == 0 || w.type == -1) return;
  for (int i = 0; i < w.child.size(); i++)
    dfs(ntow[w.child[i]]);
  if (w.type == 1) {
    for (int i = 0; i < w.child.size(); i++) {
      w.y = max(w.y, ntow[w.child[i]].y);
      w.x += ntow[w.child[i]].x;
    }
    if (w.child.size()) {
      w.y += 2*w.b;
      w.x += 2*w.b + (w.child.size()-1)*w.s;
    }
  } else if (w.type == 2) {
    for (int i = 0; i < w.child.size(); i++) {
      w.x = max(w.x, ntow[w.child[i]].x);
      w.y += ntow[w.child[i]].y;
    }
    if (w.child.size()) {
      w.x += 2*w.b;
      w.y += 2*w.b + (w.child.size() - 1)*w.s;
    }
  }
  w.type = -1;
}

int main()
{
  int n;
  cin>>n;
  while(getchar() != '\n');
  while (n--) {
    char str[1000];
    cin.getline(str, 1000);
    vector<string> op;
    for(char* cp = strtok(str, " .,()"); cp; cp = strtok(NULL, " .,()"))
      op.push_back(cp);
    if (op[0] == "Widget") ntow[op[1]] = widget(0, atoi(op[2].c_str()), atoi(op[3].c_str()));
    else if (op[0] == "HBox") ntow[op[1]] = widget(1);
    else if (op[0] == "VBox") ntow[op[1]] = widget(2);
    else if (op[1] == "set_border") ntow[op[0]].b = atoi(op[2].c_str());
    else if (op[1] == "set_spacing") ntow[op[0]].s = atoi(op[2].c_str());
    else if (op[1] == "pack") ntow[op[0]].child.push_back(op[2]);
  }
  map<string, widget>::iterator it;
  for (it = ntow.begin(); it != ntow.end(); it++) {
    dfs(it->second);
    cout<<it->first<<" "<<it->second.x<<" "<<it->second.y<<endl;
  }
  return 0;
}
