#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX_N = 2e5+7;
vector<int> G[MAX_N], station;
vector< pair<int,int> > stamp;
int in[MAX_N];
map<int, int> stoi, itos;
void dfs(int i, int par)
{
  cout<<itos[i]<<" ";
  for (int j = 0; j < G[i].size(); j++) if (G[i][j] != par) dfs(G[i][j], i);
}
int main()
{
  int n;
  cin>>n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin>>a>>b;
    station.push_back(a); station.push_back(b);
    stamp.push_back(make_pair(a, b));
  }
  sort(station.begin(), station.end());
  station.erase(unique(station.begin(), station.end()), station.end());
  for (int i = 1; i <= station.size(); i++) stoi[station[i-1]] = i, itos[i] = station[i-1];
  for (int i = 0; i < n; i++) {
    int a = stoi[stamp[i].first], b = stoi[stamp[i].second];
    G[a].push_back(b);
    G[b].push_back(a);
    in[a]++, in[b]++;
  }
  for (int i = 1; i <= station.size(); i++) if (in[i] == 1) { dfs(i, 0); cout<<endl; break; }
  return 0;
}
