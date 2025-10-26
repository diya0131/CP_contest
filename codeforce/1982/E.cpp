#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define debug if(de) cout
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool de = true;
const ll M = 1e9 + 7;

ll cnt(ll n, ll k) {
    if (k == 0) return 1;
    if (n == 0) return 0;
    int a, b, s, t;
    
    a=cnt(n / 2, k - 1) ;
    b=cnt(n / 2, k);
    if(n%2==0){
        s = 0;
        t = n/2;
        while (t > 0) {
            s++;
            t -= (t & (-t));
        }
        if(s==k-1) a--;
    }
    debug<<"cnt: "<<n _ k _ a+b<<endl;
    return a+b;
}

vector< ll > get(ll n, ll k) {

    vector < ll > a(3), b(3);
    int s = 0, t = n;
    if (k == 0 || n == 0) {
        a[0] = 0;
        a[1] = 0;
        a[2] = 1;
        return a;
    }

    if (k == 1) {
        if (n <= 3) {
            a[0] = 0;
            a[1] = 0;
            a[2] = n + 1;
            return a;
        }

        while (t > 0) {
            s++;
            t /= 2;
        }
        a[0] = s + 4;
        a[1] = s + 1;
        a[2] = 0;
        if (n == (n & (-n))) {
            a[0]--;
            a[1]--;
            a[2]++;
        }
        return a;
    }

    b = get(n / 2, k - 1);
    debug<<n/2 _ k-1 _ " = " _ b[0] _ b[1] _ b[2]<<endl;
    t = cnt(n / 2, k);
    // debug<<n/2 _ k _ " == " _ t<<endl;
    a[0] = 4 * b[0] - b[1] + t;
    a[1] = 2 * b[1] + t;




    if (b[2] == 0) {
        a[2] = 0;
        return a;
    }
    if (n % 2) {
        a[2] = 2 * b[2];
        return a;
    }
    if (a[2] > 0) {
        a[2] = 2 * b[2] - 1;
        return a;
    }
    s = 0;
    t = n;
    while (t > 0) {
        s++;
        t -= (t & (-t));
    }
    if (s <= k) {
        a[2] = 1;
        return a;
    }
    a[2] = 0;
    return a;
}



void solve() {
    ll n, m, k, i, j, s;
    cin >> n >> k;
    vector < ll > a;
    a = get(n, k);
    debug<<a[0] _ a[1] _ a[2]<<endl;
    cout<<a[0]+a[2]*(a[2]+1)/2<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}