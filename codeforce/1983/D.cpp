#include<bits/stdc++.h>

#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;
vector < int > av, bv;
map< int, int > a, b;
void mswap(bool isa, int x, int y) {
    int valx, valy, xx, yx;
    xx = x;
    yx = y;
   
    if (isa) {
        valx = av[x];
        valy = av[y];
        av[x] = valy;
        av[y] = valx;
        a[valx] = yx;
        a[valy] = xx;
    } else {
        valx = bv[x];
        valy = bv[y];
        bv[x] = valy;
        bv[y] = valx;
        b[valx] = yx;
        b[valy] = xx;
    }
}

void solve() {
    ll n, i, j, k, s = 0, ax, bx;
    cin >> n;
    av.clear(); bv.clear();
    a.clear(); b.clear();
    av.resize(n); bv.resize(n);
    map< int, int >::iterator it, jt, lt;
    pair < int, int > pr;
    for (i = 0;i < n;i++) {
        cin >> k;
        av[i] = k;
        a[k] = i;
    }
    for (i = 0;i < n;i++) {
        cin >> k;
        bv[i] = k;
        b[k] = i;
    }
    for (ax=0;ax<n;ax++) {
        if (b.find(av[ax]) == b.end()) {
            cout << "NO\n";
            return;
        }
    }
    int idx = 0;
    for (ax = 0;ax < n - 2;ax++) {
        bx = b[av[ax]];
        if (ax != bx) {
            if (bx == n - 1) {
                mswap(1, n - 2, n - 1);
                mswap(0, n - 2, n - 1);
                bx = n - 2;
            }
            mswap(1, ax + 1, bx + 1);
            mswap(0, ax, bx);
        }
        // for(i=0;i<n;i++){
        //     cout<<av[i]<<" ";
        // }
        // cout<<endl;
        //  for(i=0;i<n;i++){
        //     cout<<bv[i]<<" ";
        // }
        // cout<<"\n--------------\n";
        
    }
    if (av[n - 2] == bv[n - 2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}