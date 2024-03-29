/* Problem Link: http://www.codeforces.com/problemset/problem/152/E */
#include <iostream>
#include <cstdio>
using namespace std;
const int oo = 1e7;
int garden[111][111];
int dp[111][111][1<<7];
int way[111][111][1<<7][3];
int N, M, K;
bool path[111][111];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/* Bellman Ford */
void updateWay(int mask)
{
    for (int t = 0; t <= N*M; t++)
        for (int x = 1; x <= N; x++)
            for (int y = 1; y <= M; y++)
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                    if (dp[nx][ny][mask] > dp[x][y][mask] + garden[nx][ny]) {
                        dp[nx][ny][mask] = dp[x][y][mask] + garden[nx][ny];
                        way[nx][ny][mask][0] = 0;
                        way[nx][ny][mask][1] = x;
                        way[nx][ny][mask][2] = y;
                    }
                }
}
/* Divide & Conquer */
void genPath(int x, int y, int mask)
{
    path[x][y] = true;
    if (way[x][y][mask][0] == 0) genPath(way[x][y][mask][1], way[x][y][mask][2], mask);
    else if (way[x][y][mask][0] == 1) {
        genPath(x, y, way[x][y][mask][1]);
        genPath(x, y, way[x][y][mask][2]);
    }
}
int main()
{
    cin>>N>>M>>K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) cin>>garden[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 0; k < 1<<K; k++) dp[i][j][k] = oo, way[i][j][k][0] = -1;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin>>x>>y;
        dp[x][y][1<<i] = garden[x][y];
        way[x][y][1<<i][0] = -1;
    }
    /* DP + Bitmask */
    for (int mask = 1; mask < (1<<K); mask++) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                for (int smask = (mask-1)&mask; smask; smask = (smask-1)&mask) {
                    int com = dp[i][j][smask] + dp[i][j][mask^smask] - garden[i][j];
                    if (dp[i][j][mask] > com) {
                        dp[i][j][mask] = com;
                        way[i][j][mask][0] = 1;
                        way[i][j][mask][1] = smask;
                        way[i][j][mask][2] = mask^smask;
                    }
                }
        updateWay(mask);
    }
    int ans = oo;
    int bx, by;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (ans > dp[i][j][(1<<K)-1])
                ans = dp[i][j][(1<<K)-1], bx = i, by = j;

    genPath(bx, by, (1<<K)-1);

    cout<<ans<<endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cout<<(path[i][j]?'X':'.');
        cout<<endl;
    }
	return 0;
}