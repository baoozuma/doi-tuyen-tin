#include <bits/stdc++.h>
using namespace std;
long long int k,dem,delta,b,t;
ifstream fi("TONG.INP");
ofstream fo("TONG.OUT");
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fi >> k;
    dem = 0;
    for (long long int a = 1; a < k; a++) {
        delta = 1 + 4*a*a - 4*a + 8*k;
        if ( delta >= 0) {
            t = sqrt(delta);
            if ( t*t == delta) {
                b = (-1 +sqrt(delta))/2;
                if ( b > a && b > 1) dem ++;
            }
        }
    }
    fo << dem;
    return 0;
}
