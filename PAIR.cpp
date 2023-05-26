#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define pf push_front
#define fr(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define ep emplace_back
long long int m,n,a[1000000],check[1000000],dem;
ifstream fi("PAIR.INP");
ofstream fo("PAIR.OUT");
int main() {
    fi >> n >> m;
    fr(i,1,n) if (a[i] >= n/2 && a[i] <= n) a[i] = n - a[i];
    sort(a, a + n + 1);
    fo << dem;


}
