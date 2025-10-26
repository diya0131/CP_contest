#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second


using namespace std;

const int N = 3e5 + 5, M = 10, MA = 1e6 + 1;

ll st[4 * N][M];
int lz[4 * N];
int val[MA];

void build(int* a, int v, int tl, int tr) {
    lz[v]=0;
    int k;
    if (tl == tr) {
        k = a[tl];
        for (int i = 0;i < M;i++) {
            st[v][i] = k;
            k = val[k];
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    for (int i = 0;i < M;i++) st[v][i] = st[2 * v][i] + st[2 * v + 1][i];
}

void push(int v){
    if(lz[v]==0) return;
    lz[2*v]+=lz[v];
    lz[2*v]+=lz[v];
}

void replace(int v, int tl, int tr, int l, int r){
    if(l>r) return;
    if(tl==l && tr == r){
        lz[v]++;
        if()
    }
    int tm = (tl+tr)/2;
    push();
}

void solve() {
    ll n, m, i, j, k, s, t, l, r;
    cin >> n >> m;
    ll a[n];
    for (i = 0;i < n;i++) cin >> a[i];
    build(a, 1, 0, n - 1);

    while(m--){
        cin>>k>>l>>r;
        l--; r--;
        if(k==1){
            replace(1, 0, n-1, l, r);
        } else {

        }
    }
}

int main() {
    for (int i = 0;i < MA;i++) val[i] = 2;
    int sq = sqrt(MA), q, k, m;
    val[1] = 1;
    for (int i = 2;i <= sq;i++) {
        if (val[i] == 2) {
            k = i * 2;
            while (k < MA) {
                m = 1;
                q = k;
                while (q % i == 0) {
                    q /= i;
                    m++;
                }
                val[k] *= m;
                k += i;
            }
        }
    }
    cin >> m;
    while (m--) solve();
}