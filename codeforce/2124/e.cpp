#include<bits/stdc++.h>
#include<chrono>
#include <random>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    ll n, a, b, s, i, j, x, t, m;
    cin>>n;
    s=0;
    vector<ll>v(n+1, 0);
    for(i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    if(s%2){
        cout<<-1<<endl;
        return;
    }
    a=0;
    b=s - v[0];
    for(i=0;i<n;i++){
        if(a<=b && a+v[i]>=b && a+b>=v[i]){
            x = (a+v[i] - b)/2;
            if(x==0){
                cout<<1<<endl;
                for(j=0;j<n;j++){
                    cout<<v[j]<<" ";
                }
                cout<<endl;
                return;
            }
            cout<<2<<endl;
            t = x;
            for(j=0;j<i;j++){
                m = min(t, v[j]);
                v[j]-=m;
                t-=m;
                cout<<m<<" ";
            }
            cout<<x<<" ";
            v[i]-=x;
            for(j=i+1;j<n;j++){
                cout<<0<<" ";
            }
            cout<<endl;
            for(j=0;j<n;j++){
                cout<<v[j]<<" ";
            }
            cout<<endl;
            return;
        }
        if(a>=b && a<=v[i]+b && a+b>=v[i]){
            x = (b+v[i] - a)/2;
            if(x==0){
                cout<<1<<endl;
                for(j=0;j<n;j++){
                    cout<<v[j]<<" ";
                }
                cout<<endl;
                return;
            }
            cout<<2<<endl;
            t = x;
            for(j=0;j<i;j++){
                cout<<0<<" ";
            }
            cout<<x<<" ";
            v[i]-=x;
            for(j=i+1;j<n;j++){
                m = min(t, v[j]);
                v[j]-=m;
                t-=m;
                cout<<m<<" ";
            }
            cout<<endl;
            for(j=0;j<n;j++){
                cout<<v[j]<<" ";
            }
            cout<<endl;
            return;
        }
        if(a>b) break;
        a+=v[i];
        b-=v[i+1];
    }
    cout<<-1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}