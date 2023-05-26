#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define fr(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
lli Heap[15001],m,n,k,nHeap,a[50002],b[50002],r;
void Push(lli x) {
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
    cin >> m >> n >> k;
    fr(i,1,m) cin >> a[i];
    fr(i,1,n) cin >> b[i];
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    fr(i,1,m) {
        fr(j,1,n) {
            Push(a[i] + b[j]);
        }
    }
    cout << endl;
    fr(i,1,k) cout << Heap[i] << endl;
}
