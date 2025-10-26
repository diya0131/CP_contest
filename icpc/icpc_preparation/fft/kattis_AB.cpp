#include<bits/stdc++.h>
#include<complex>

#define ll long long
#define _ <<" "<<
#define cd complex<double>

using namespace std;

const double PI = acos(-1);

const ll N = 1e5;

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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, i, s, k, j, res=0;
    cin>>n;
    vector < ll > a(N+1, 0), c, b;
    map < ll, ll > mp;
    for(i=0;i<n;i++){
        cin>>k;
        mp[k]++;
        a[k+N/2]++;
    }
    b=a;
    c=multiply(a, b);
    for(i=N/2;i<=N+N/2;i++){
        if(mp.find(i-N)!=mp.end()){
            k=c[i];
            if(i%2==0 && mp.find(i/2-N/2)!=mp.end()) k-=mp[i/2-N/2];
            res+=k*mp[i-N];
        }
    }
    if(mp[0]){
        k=mp[0];
        res-=k*(k-1)*k;
        res+=k*(k-1)*(k-2)/3;
        res-=k*(n-k)*2;
    }
    cout<<res<<endl;
}