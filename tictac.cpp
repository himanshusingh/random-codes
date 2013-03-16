#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
const int oo = 1e9+7;
char g[6][6];
bool c1(int i, int j) {
	for (int k = j; k < j + 2; k++) if (g[i][k] != g[i][k+1]) return false;
	return true;
}
bool c2(int i, int j) {
	for (int k = i; k < i + 2; k++) if (g[k][j] != g[k+1][j]) return false;
	return true;
}
bool c3(int i, int j) {
	for (int k = 0; k < 2; k++) if (g[i+k][j+k] != g[i+k+1][j+k+1]) return false;
	return true;
}
bool c4(int i, int j) {
	for (int k = 0; k < 2; k++) if (g[i+k][j-k] != g[i+k+1][j-k-1]) return false;
	return true;
}
int main()
{
	int tests;
	scanf ("%d", &tests);
	while (tests--) {
		for (int i = 0; i < 5; i++)
			scanf ("%s", g[i]);
		bool a = 0, b = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if ((j+2 < 5) && c1(i, j)) {
					if (g[i][j] == 'A') a = true;
					else b = true;
				}
				if ((i + 2 < 5) && c2(i, j)) {
					if (g[i][j] == 'A') a = true;
					else b = true;
				}
				if ((i + 2< 5) && (j + 2< 5) && c3(i, j)) {
					if (g[i][j] == 'A') a = true;
					else b = true;
				}
				if ((i + 2 < 5) && j > 1 && c4(i, j)) {
					if (g[i][j] == 'A') a = true;
					else b = true;
				}
			}
		}
		if (a != b) {
			if (a) printf ("A wins\n");
			else printf ("B wins\n");
		} else {
			printf ("draw\n");
		}
	}
	return 0;
}