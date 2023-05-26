#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
priority_queue<lli, vector<lli>, less<lli> > Hmax;
priority_queue<lli, vector<lli>, greater<lli> > Hmin;
lli a[10000001],p,k,q;
int main() {
    do {
        cin >> q;
        if (q == 1) {
            cin >> k >> p;
            Hmax.push(p);
            Hmin.push(p);
            a[p] = k;
        }
        if (q == 2) {
            while (!Hmax.empty() && (a[Hmax.top()] == -1)) Hmax.pop();
            if (Hmax.empty() == true ) cout << 0 << endl;
            else {
                cout << a[Hmax.top()] << endl;
                a[Hmax.top()] = -1;
                Hmax.pop();
            }
        }
        if (q == 3) {
            while (!Hmin.empty() && (a[Hmin.top()] == -1)) Hmin.pop();
            if (Hmin.empty() == true ) cout << 0 << endl;
            else {
                cout << a[Hmin.top()] << endl;
                a[Hmin.top()] = -1;
                Hmin.pop();
            }

        }
    }while( q != 0);
    return 0;
}
