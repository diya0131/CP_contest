// https://www.spoj.com/problems/ADAMATCH/

#include <bits/stdc++.h>
#include <complex>
#define ll long long
#define _ <<" "<<

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

void solve(string & s, string& t){
    ll n=s.size(), i, j, m=t.size(), mi=0;
    vector < ll > rs(m+n-1, 0);
    vector < ll > a(n), b(m), c;
    char chrs[4]{'A', 'C', 'T', 'G'};
    for(i=0;i<4;i++){
        for(j=0;j<n;j++){
            if(s[j]==chrs[i]){
                a[j]=1;
            } else {
                a[j]=0;
            }
        }
        for(j=0;j<m;j++){
            if(t[j]==chrs[i]){
                b[m-1-j]=1;
            } else {
                b[m-1-j]=0;
            }
        }
        c=multiply(a, b);
        for(j=0;j<n+m-1;j++){
            rs[j]+=c[j];
        }
    }
    for(i=m-1;i<n;i++){
        // cout<<rs[i] _ i<<endl;
        mi = max(mi, rs[i]);
    }
    cout<<m-mi<<endl;
}


int main() {
    
    string s, t;
    int k=1;
    // cin>>k;
    while(cin>>s){
        cin>>t;
        solve(s, t);
    }
   
    
}