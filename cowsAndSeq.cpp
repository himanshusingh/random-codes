#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 2e5+7;
int val[MAX_N], add[MAX_N];
int main()
{
//	freopen("in.in", "r", stdin);
	int n;
	cin>>n;
	int elem = 1;
	double sum = 0;
	while (n--) {
		int t;
		cin>>t;
		if (t == 1) {
			int a, x;
			cin>>a>>x;
			sum += a*x;
			add[a] += x;
		} else if (t == 2) {
			int k;
			cin>>k;
			val[++elem] = k;
			sum += k;
		} else {
			if (elem <= 1) continue;
			sum -= val[elem] + add[elem];
			add[elem-1] += add[elem];
			add[elem] = 0;
			elem--;
		}
		printf ("%0.12lf\n", (sum*1.0f)/elem);
	}

	return 0;
}