#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int a[3];
bool dp[303][303];
int main()
{

	cin>>n;
	for (int i = 0; i < n; i++) cin>>a[i];
	bool lgm = true;
	if (n == 1) lgm = (a[0]!=0);
	else if (n == 2) {
		for (int i = 1; i <= max(a[0],a[1]); i++) dp[i][0] = dp[0][i] = true;
		for (int i = 1; i <= a[0]; i++)
			for (int j = 1; j <= a[1]; j++) {
				bool mov = 1;
				for (int k = i; k > 0; k--) mov &= dp[i-k][j];
				for (int k = j; k > 0; k--) mov &= dp[i][j-k];
				for (int k = min(i, j); k > 0; k--) mov &= dp[i-k][j-k];
				if (!mov) dp[i][j] = true;
			}
		lgm = dp[a[0]][a[1]];
	} else if (n == 3) {
		lgm = ((a[0]^a[1]^a[2]) != 0);
	}
	if (lgm)
		cout<<"BitLGM"<<endl;
	else
		cout<<"BitAryo"<<endl;
	return 0;
}