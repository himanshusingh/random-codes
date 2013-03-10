#include <iostream>
#include <cstdio>
using namespace std;
long long pow(long long x, long long p, long long mod)
{
	long long ret = 1;
	while (p) {
		if (p&1) ret = (ret*x)%mod;
		x = (x*x)%mod;
		p /= 2;
	}
	return ret;
}
 long long factmod ( long long n, long long p ) {
	long long res = 1 ;
	while ( n > 1 ) {
		res = ( res * ( ( n / p ) % 2 ? p - 1 : 1 ) ) % p ;
		for ( long long i = 2 ; i <= n % p ; ++ i )
			res = ( res * i ) % p ;
		n /= p ;
	}
	return res % p ;
} 
int main()
{
//	freopen("in.in", "r", stdin);
	int test;
	scanf ("%d", &test);
	while (test--) {
		long long n, p;
		scanf ("%Ld %Ld", &n, &p);

		printf ("%Ld\n", factmod(n, p));
	}
	return 0;
}