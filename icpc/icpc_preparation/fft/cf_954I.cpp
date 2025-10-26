// https://www.spoj.com/problems/ADAMATCH/

#include <bits/stdc++.h>
#include <complex>
#define ll long long
#define _ <<" "<<

#define cd complex<double>

using namespace std;

const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
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
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) n <<= 1;
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

void solve(string& s, string& t) {
    ll n = s.size(), i, j, m = t.size(), mi = 0, i1;
    vector < ll > rs(m + n - 1, 0);
    vector < ll > a(n), b(m), c, a1(n), b1(m), c1;
   
    bool vis[n][6];
    for(i=0;i<n;i++){
        for(j=0;j<6;j++){
            vis[i][j]=0;
        }
    }
    for (i = 0;i < 6;i++) {
        for (i1 = i + 1;i1 < 6;i1++) {

            for (j = 0;j < n;j++) {
                if (s[j] == 'a' + i) {
                    a[j] = 1;
                } else {
                    a[j] = 0;
                }
                if (s[j] == 'a' + i1) {
                    a1[j] = 1;
                } else {
                    a1[j] = 0;
                }
            }
            for (j = 0;j < m;j++) {
                if (t[j] == 'a' + i1) {
                    b[m - 1 - j] = 1;
                } else {
                    b[m - 1 - j] = 0;
                }
                if (t[j] == 'a' + i) {
                    b1[m - 1 - j] = 1;
                } else {
                    b1[m - 1 - j] = 0;
                }
            }
            c = multiply(a, b);
            c1 = multiply(a1, b1);
            for (j = m - 1;j < n;j++) {
                // cout<<c[j]<<" ";

                if (c[j] || c1[j]) {
                    if(!(vis[j][i] && vis[j][i1])){
                        rs[j]++;
                        if(vis[i]) vis[j][i1]=1;
                        else vis[j][i]=1;
                    }
                    // cout<<i _ i1 _ j-m+1 _ rs[j]<<endl; 
                }
            }
            // cout<<endl;

        }
    }
    for (i = m - 1;i < n;i++) {
        // cout<<rs[i] _ i<<endl;
        cout << rs[i] << " ";
    }
    // cout << "here\n";
    // cout << endl;
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    solve(s, t);



}