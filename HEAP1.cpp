#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define X first
#define Y second
#define pb push_back
#define fr(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
lli n, Heap[20001],T,x,y,nHeap;
lli s;
void Push(int x) {
    int child, parent;
    nHeap++;
    child = nHeap;
    parent = child/2;
    while(parent > 0 && Heap[parent] > x) {
        Heap[child] = Heap[parent];
        child = parent;
        parent = child/2;
    }
    Heap[child] = x;
}
void Pop() {
    int x, child, parent;
    x = Heap[nHeap];
    nHeap--;
    parent = 1;
    while(2*parent <= nHeap) {
        child = 2*parent;
        if(child + 1 <= nHeap && Heap[child+1] < Heap[child]) child++;
        if(Heap[child] >= x) break;
        Heap[parent] = Heap[child];
        parent = child;
    }
    Heap[parent] = x;
}
int main() {
    cin >> T;
    while(T--) {
        int nHeap = 0;
        cin >> n;
        fr(i,1,n) {
            cin >> x;
            Push(x);
        }
        s = 0;
        while(nHeap > 1) {
            x = Heap[1]; Pop();
            y = Heap[1]; Pop();
            s += x + y;
            Push(x + y);
        }
        cout << s << endl;
    }

}
