#include<bits/stdc++.h>

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

const bool TEST = 0;

vector < ll > st, lz;

void push(ll v){
    ll mi=min(st[v], lz[v]);
    lz[2*v]=min(lz[2*v], mi);
    lz[2*v+1]=min(lz[2*v+1], mi);
    st[2*v]=min(st[2*v], lz[2*v]);
    st[2*v+1]=min(st[2*v+1], lz[2*v+1]);
}

ll get(ll v, ll tl, ll tr, ll k){
    test<<"get" _ v _ tl _ tr _ k<<endl;
    if(tl==tr){
        return st[v];
    }
    ll tm =(tl+tr)/2;
    push(v);
    if(tm>=k) return get(2*v, tl, tm, k);
    return get(2*v+1, tm+1, tr, k);
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll mi){
    test<<"udp" _ v _ tl _ tr _ l _ r _ mi<<endl;
    if(l>r) return;
    if(tl==l && tr==r){
        st[v]=min(st[v],mi);
        lz[v]=min(lz[v],mi);
        return;
    }
    push(v);
    ll tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, min(tm, r), mi);
    upd(2*v+1, tm+1, tr, max(l, tm+1), r, mi);
}


void solve() {
    ll n, i, j, s, mx=0, k, t, c;
    cin>>n;
    vector < ll > a(n), b(n), dp(n), su(n);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) {
        cin>>b[i];
        b[i]--;
    }
    s=0;
    for(i=0;i<n;i++){
        s+=a[i];
        su[i]=s;
    }
    st.clear();
    lz.clear();
    st.assign(4*n, LLONG_MAX);
    lz.resize(4*n, LLONG_MAX);
    i=0;
    j=0;
    upd(1, 0, n-1, 0, 0, 0);
    do{
        i=mx;
        while(j<=i){
            if(j<b[j]){
                c=get(1, 0, n-1, j);
                upd(1, 0, n-1, j+1, b[j], c+a[j]);
            }
            mx=max(b[j], mx);
            j++;
        }
    }while(i<mx);
    mx=0;
    s=0;
    for(i=0;i<n;i++){
        s+=a[i];
        test<<s _ get(1, 0, n-1, i)<<endl;
        mx=max(mx, s-get(1,0,n-1,i));
    }
    cout<<mx<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}