#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;

const ll N = 1e7 + 5;

vector < bool > isP(N, 1);

void solve() {
    ll n, i, j, k, s;
    cin >> n;
    map < ll, ll > mp;
    for (i = 0;i < n;i++) {
        cin >> k;
        if (isP[k]) s++;
    }
    if (s % 2) cout << "Alice\n";
    else cout << "Bob\n";
}


int main() {
    int i, t, k;
    cin >> t;
    for (i = 2;i * i <= N;i++) {
        k = i * 2;
        while (k < N) {
            isP[k] = 0;
            k += i;
        }
    }
   
    while (t--) {
        solve();
    }
}