#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define X first
#define Y second
#define pb push_back
#define fr(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
const int mxN = 1e5+5;
vector<ii>v;
vi x;
int n,k,a[mxN],res;
bool cmp(ii a, ii b) {
    return (a.Y>b.y ||(a.Y==b.Y&&a.X<b.X));
}
int main() {
    ifstream fi("LOPXE.INP");
    ofstream fo("LOPXE.OUT");
    cin>>n>>k;
    fr(i,1,n) cin>>a[i];
    fr(i,1,n) {
        if(a[i] > 30) {
            res += 2;
            x.pb(i);
            k--;
        }
    }
    if (k<0) {
        cout << -1;
        return 0;
    }
    if(x.size() == 0) {
        cout <<0;
        return 0;
    }
    fr(i,0,x.size()-1) {
        if(i==x.size() - 1) v.pb((n-x[i],1));
        else v.pb((x[i+1]-x[i]-1,2));
    }
    sort(ALL(v),cmp);
    int pos = 0;
    while(k >= 0 && pos<v.size()) {
        if(k>=v[pos].X) {
            res-=v[pos].Y;
            k-=v[pos].X;
        }
        ++pos;
    }
    cout << res;
}

