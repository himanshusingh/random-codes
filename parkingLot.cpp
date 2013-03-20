#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 1e5+7;
int lot[MAX_N];
int frw[MAX_N], bck[MAX_N];
int pos[MAX_N], len[MAX_N];
int main()
{
	int L, b, f, N;
	cin>>L>>b>>f;
	cin>>N;
    L--;
    for (int i = 1; i <= N; i++) {
      int op;
      cin>>op;
      if (op == 1) {
        cin>>len[i];
        if (!lot[L]) frw[L] = f;
        else frw[L] = -1;
        for (int l = L-1; l >= 0; l--)
            if (!lot[l]) frw[l] = frw[l+1] + 1;
        else frw[l] = -1;

        if (!lot[0]) bck[0] = b;
        else bck[0] = -1;
        for (int l = 1; l <= L; l++)
            if (!lot[l]) bck[l] = bck[l-1]+1;
        else bck[l] = -1;

        bool ok = false;
        for (int l = 0; l <= L; l++)
            if (bck[l] + frw[l] + 1 >= len[i]+b+f && bck[l] >= b && frw[l]-len[i]+1 >= f && l+len[i]-1<=L) {
                ok = true;
                cout<<l<<endl;
                for(int j = l; j < l + len[i]; j++) lot[j] = i;
                    pos[i] = l;
                break;
            }

        if (!ok)
            cout<<"-1"<<endl;
        } else {
            int id;
            cin>>id;
            for (int j = pos[id]; j < pos[id] + len[id]; j++) lot[j] = 0;
        }
    }
    return 0;
}