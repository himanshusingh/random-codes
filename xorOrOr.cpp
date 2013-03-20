#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{

	string a, b;
	cin>>a>>b;
	if (a.size() != b.size()) {
		cout<<"NO"<<endl;
		return 0;
	}
	int aone = 0, bone = 0;
	for (int i = 0; i < a.size(); i++) aone += a[i]-'0', bone += b[i]-'0';

	if ((aone>0) != (bone>0))
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}