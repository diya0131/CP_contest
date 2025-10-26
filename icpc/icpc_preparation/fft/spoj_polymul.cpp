//https://www.spoj.com/problems/POLYMUL/

#include <bits/stdc++.h>
#include <complex>
#define ll long long

#define cd complex<double>

using namespace std;

const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) n<<=1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve(){
    ll n, i, j;
    cin>>n;
    vector < ll > a(n+1), b(n+1), c;
    for(i=0;i<=n;i++){
        cin>>a[i];
    }
    for(i=0;i<=n;i++){
        cin>>b[i];
    }
    c = multiply(a, b); 
    cout<<c[0];
    for(i=1;i<=2*n;i++){
        cout<<" "<<c[i];
    }
    cout<<endl;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}