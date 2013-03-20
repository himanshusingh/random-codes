#include <cstdio>
#include <iostream>
using namespace std;
char perm[111], a[111], b[111];
int rank[30];
int ca[30], cb[30];
bool seen[30];
int main()
{
//	freopen("in.in", "r", stdin);
	int tests;
	scanf ("%d", &tests);
	scanf ("%s", perm);
	for (int i = 0; perm[i]; i++) rank[perm[i]-'a'] = i;
	while (tests--) {
		scanf ("%s", a);
		scanf ("%s", b);

		for (int i = 0; i < 26; i++) seen[i] = false, ca[i] = 0, cb[i] = 0;

		for (int i = 0; a[i]; i++) ca[a[i]-'a']++;
		for (int i = 0; b[i]; i++) cb[b[i]-'a']++;
		for (int i = 0; i < 26; i++) seen[i] = false, ca[i] = (cb[i] = min(ca[i], cb[i]));
		int al = 0, bo = 0;

	    for (int i = 0; a[i]; i++) {
			int x = a[i]-'a';
			if (ca[x]) { ca[x]--; continue; }
			if (seen[x]) continue;
			seen[x] = true;
			al += rank[x];
		}

		for (int i = 0; i < 26; i++) seen[i] = false;
		for (int i = 0; b[i]; i++) {
			int x = b[i]-'a';
			if (cb[x]) { cb[x]--; continue; }
			if (seen[x]) continue;
			seen[x] = true;
			bo += rank[x];
		}

		if (al > bo)
			printf("ALICE\n");
		else if (bo > al)
			printf("BOB\n");
		else
			printf("TIE\n");
	}

	return 0;
}