#include <bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
typedef long long int lli;
priority_queue<lli, vector<lli>, less<lli> > diem, rect;
lli value,temp = -1,n,k,recent;
int main() {
    cin >> k;
    while(k--) {
            cin >> n;
            fr(i,1,n) {
            cin >> value;
            diem.push(value);
        }
        while (!diem.empty()) {
            if(diem.top() == temp ) {
                rect.push(diem.top());
                temp = -1;
            }
            else temp = diem.top();
            diem.pop();
        }
        if(rect.size() < 2) cout << -1;
        else {
            temp = rect.top();
            rect.pop();
            cout << temp*rect.top();
        }
        while(!rect.empty()) rect.pop();
        cout << endl;
        temp = -1;

    }

}
