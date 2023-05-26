#include <bits/stdc++.h>
using namespace std;
int N, a[100],dq[100],x = 1000,y = -1000;
ifstream fi("KEOCO.INP");
ofstream fo("KEOCO.OUT");
void Result() {
    int s1 = 0, s2 = 0,dem1 = 0, dem2 = 0;
    for (int i = 1; i <= N; i++) {
        if (dq[i] == 1) {
            s1 = s1 + a[i];
            dem1++;
        }
        else {
            s2 = s2 + a[i];
            dem2++;
        }
    }
    if (abs(s1 - s2) <= abs(x - y) && abs(dem1 - dem2) <= 1) {
        x = s1;
        y = s2;
    }
}
void BackTrack(int i) {
    for (int j = 0; j <= 1; j++) {
        dq[i] = j;
        if (i < N) BackTrack(i + 1);
        else {
            Result();
        }
    }
}
int main() {
    fi >> N;
    for (int i = 1; i <= N; i++) fi >> a[i];
    BackTrack(1);
    fo << min(x,y) << " " << max(x,y);
}
