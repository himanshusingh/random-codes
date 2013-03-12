/* Problem Link: http://www.codeforces.com/problemset/problem/280/B */
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int MAX_N = 1e5+7;
int seq[MAX_N];
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>seq[i];
    stack<int> st;
    
    int ans = 0;
    st.push(seq[1]);
    for (int i = 2; i <= n; i++) {
        while (!st.empty() && st.top() < seq[i]) ans = max(ans,seq[i]^st.top()), st.pop();
        if (!st.empty()) ans = max(ans, seq[i]^st.top());
        st.push(seq[i]);
    }
    cout<<ans<<endl;
    return 0;
}