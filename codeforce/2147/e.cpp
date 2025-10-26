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

vector<ll>pw(35);

int count(ll k){
    int s=0;
    while(k){
        if(k%2) s++;
        k/=2;
    }
    return s;
}

int last(ll k){
    for(int i=0;i<35;i++){
        if(k%2==0) return i;
        k/=2;
    }
    cout<<"error\n";
    return 0;
}

ll cxor(vector<ll>& vc){
    ll res =0;
    for(ll num:vc) res = res | num;
    return res;
}

ll findmin(vector<ll>& vc, ll k){
    ll mi=pw[k] - vc[0] % pw[k], mix=0;
    for(int i=1;i<vc.size();i++){
        if(pw[k] - vc[i] % pw[k] < mi){
            mi = pw[k] - vc[i] % pw[k];
            mix = i;
        }
    }
    return mix;

}

void solve() {
    ll n, q, s, t, i, j, k, p, x =0, add=0, idx, tadd, tk, c;
    cin>>n>>q;
    vector <ll > b(n);
    // vector<vector<ll>>a(n, vector<ll>(34));

    // vector<set<pair<ll, ll>>>st(34);
    
    
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    x = cxor(b);
    ll first = count(x);
    vector<ll>res(34, 0);
    for(int i1=first+1;i1<34;i1++){
        
        x = cxor(b);
        k = last(x);
        // cout<<i1 _ x _ k<<endl;
        idx = findmin(b, k);
        tadd = pw[k] - b[idx]%pw[k];
        add += tadd;
        b[idx] += tadd;
        // cout<<i1 _ x _ k _ pw[k] _ idx _ tadd _ b[idx]<<endl;
        // while(last(cxor(b))<k){
        //     cout<<last(cxor(b)) _ "hey\n";
        //     tk = last(cxor(b));
        //     idx = findmin(b, tk);
        //     tadd = pw[tk] - b[idx]%pw[tk];
        //     add+=tadd;
        //     b[idx]+=tadd;
        //     cout<<"fix" _ tadd _ idx _ b[idx] _ cxor(b) _ last(cxor(b))<<endl;
        // }
        for(int i2=k-1;i2>=0;i2--){
            if((cxor(b) & pw[i2]) == 0){
                idx = findmin(b, i2);
                tadd = pw[i2] - b[idx]%pw[i2];
                add+=tadd;
                b[idx]+=tadd;
            }
        }
        res[i1]=add;
    }
    // cout<<"ready\n";
    // for(int i=0;i<35;i++){
    //     cout<<i _ res[i]<<endl;
    // }
    while(q--){
        cin>>c;
        for(int i=0;i<35;i++){
            if(res[i]>c) {
                cout<<i-1<<endl;
                break;
            }
        }
    }
}

int main() {
    // BOOST
    pw[0]=1;
    for(int i=1;i<35;i++){
        pw[i]=pw[i-1]*2;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}