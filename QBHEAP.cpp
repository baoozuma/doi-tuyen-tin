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
string input;
int add,Heap[15001],a[15001];
int nHeap;
void Push(int x) {
    int child, parent;
    nHeap++;
    child = nHeap;
    parent = child/2;
    while(parent > 0 && Heap[parent] < x) {
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
        if(child + 1 <= nHeap && Heap[child+1] > Heap[child]) child++;
        if(Heap[child] <= x) break;
        Heap[parent] = Heap[child];
        parent = child;
    }
    Heap[parent] = x;

}
int main() {
    char ch;
    nHeap = 0;
    while(cin >> ch) {
        if (ch == '+') {
            cin >> add;
            if (nHeap < 15000) Push(add);
        }
        else {
            if(nHeap > 0) {
                add = Heap[1];
                while(nHeap > 0 && Heap[1] == add) Pop();
            }
        }
    }
    int k = 0;
    while(nHeap > 0) {
        k++;
        a[k] = Heap[1];
        while(nHeap > 0 && a[k] == Heap[1]) Pop();
    }
    cout << k << endl;
    for(int i = 1; i <= k; i++) cout << a[i] << endl;
}
