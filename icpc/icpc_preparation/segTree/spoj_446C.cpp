#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define add(v, ad) v=(v+ad)%M
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

const ll N =4*300000, M=1e9+9;

ll st[N], lza[N], lzb[N], n;
ll fibo[N/4+10], pref[N/4+10];

ll getFibo(ll a, ll b, ll k){
    if(k==0) return a;
    // cout<<a _ fibo[k-1] _ b _ fibo[k] _ k<<endl;
    return (a*fibo[k-1]%M+b*fibo[k]%M)%M;
}

ll getSum(ll a, ll b, ll k){
    // cout<< "sum" _ a _ b _ k <<endl;
    if(k==1) return a;
    return (a*(pref[k-2]+1)%M+b*pref[k-1]%M)%M;
}

void build(vector < ll>& a, ll v, ll tl, ll tr){
    if(tl==tr){
        st[v]=a[tl];
        lza[v]=0;
        lzb[v]=0;
        return;
    }
    ll tm=(tl+tr)/2;
    build(a, 2*v, tl, tm);
    build(a, 2*v+1, tm+1, tr);
    st[v]=(st[2*v]+st[2*v+1])%M;
}

void push(ll v, ll tl, ll tr, ll tm){
    if(lza[v]==0 && lza[v]==0) return;
    add(lza[2*v],lza[v]);
    add(lzb[2*v],lzb[v]);
    ll tmfa=getFibo(lza[v], lzb[v], tm-tl+1);
    ll tmfb=getFibo(lza[v], lzb[v], tm-tl+2);
    add(lza[2*v+1], tmfa);
    add(lzb[2*v+1], tmfb);
    test<<"hmm" _ tm-tl _ tmfa _ tmfb _ tr-tm<<endl;
    test<<"push" _ tl _ tr _ lza[v] _ lzb[v] _ getSum(lza[v] ,lzb[v], tm-tl+1) _ getSum(tmfa, tmfb, tr-tm)<< endl;
    add(st[2*v], getSum(lza[v], lzb[v], tm-tl+1));
    add(st[2*v+1], getSum(tmfa, tmfb, tr-tm));
   
    lza[v]=0;
    lzb[v]=0;
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    // test<<"get" _ v _ tl _ tr _ l _ r<<endl;
    if(l>r) return 0;
    if(tl==l && tr==r){
        test<<"leaf sum" _ v _ st[v] _ lza[v] _ tl _ tr _ l _ r<<endl;
        return (st[v])%M;
    }
    ll tm = (tl+tr)/2;
    push(v, tl, tr, tm);
    // st[v]=(st[2*v]+st[2*v+1])%M;
    return (get(2*v, tl, tm, l, min(tm, r))+get(2*v+1, tm+1, tr, max(l, tm+1), r))%M;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll k){
    test<<"upd" _ tl _ tr _ l _ r _ k<<endl;
    if(l>r) return;
    if(tl==l && tr==r){
        test<<"end upd" _ tl _ tr _ pref[k+tr-tl]-pref[k-1] _ fibo[k] _ fibo[k+1] _ k<<endl;
        add(lza[v],fibo[k]);
        add(lzb[v],fibo[k+1]);
        add(st[v], (pref[k+tr-tl]-pref[k-1])%M+M);
        test<<st[v]<<endl;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v, tl, tr, tm);
    upd(2*v, tl, tm, l, min(tm, r), k);
    upd(2*v+1, tm+1, tr, max(l, tm+1), r, k+tm-tl+1);
    st[v]=(st[2*v]+st[2*v+1])%M;
}

void solve() {
    ll m, i, j, k, s, t, c, l, r;
    cin>>n>>m;
    vector < ll > a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    build(a, 1, 0, n-1);
    while(m--){
        cin>>c>>l>>r;
        l--;
        r--;
        // test<<"here " _ c<<endl;
        if(c==1){
            upd(1, 0, n-1, l, r, 1-l);
        } else {
            s=get(1, 0, n-1, l, r);
            cout<<(s%M+M)%M<<endl;
        }
    }

}

int main() {
    BOOST
    fibo[0]=0;
    fibo[1]=1;
    ll s=1;
    pref[0]=0;
    pref[1]=1;
    for(ll i=2;i<N/4+10;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%M;
        s=(s+fibo[i])%M;
        pref[i]=s;
    }

    solve();
   
}