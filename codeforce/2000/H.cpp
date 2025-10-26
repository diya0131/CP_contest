#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ <<" "<<
#define test if(te) cout

using namespace std;

const bool te =1;
const ll N = 2e6+1;

pair< int, int > sd[N+2];

int st[4*N];
bool a[N+2];

void build(ll v, ll tl, ll tr){
    if(tl==tr){
        if(a[tl]) st[v]=sd[tl].ss - tl;
        else st[v]=0;
        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1,tr);
    st[v]=max(st[2*v], st[2*v+1]);
}

void change(ll v, ll tl, ll tr, ll k){
    if(tl==tr){
        if(a[tl]) st[v]=sd[tl].ss - tl;
        else st[v]=0;
        return;
    }
    ll tm = (tl+tr)/2;
    if(k>tm) change(2*v+1, tm+1, tr, k);
    else change(2*v, tl, tm, k);
    st[v]=max(st[2*v], st[2*v+1]);
}



void solve(){
    ll n, i, j, k, s, t, m, pre, nxt, l, r, v,mid;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        a[k]=1;
    }
    k=0;
    for(i=1;i<=N+1;i++){
        sd[i].ff = k;
        if(a[i]) k=i;
    }
    k=N+1;
    for(i=N+1;i>=0;i--){
        sd[i].ss = k;
        if(a[i]) k=i;
    }
    a[0]=1;
    build(1, 0, N);
    cin>>m;
    char ch;
    while(m--){
        test<<m _ "--------------\n";
        cin>>ch>>k;
        if(ch=='?'){
            l=0, r=N;
            v=1;
            if(st[v]>k){
                while(l<r){
                    mid=(l+r)/2;
                    test<<l _ r _ st[2*v] _ k<<endl;
                    if(st[2*v]>k){
                        v=2*v;
                        r=mid;
                    } else {
                        v=2*v+1;
                        l=mid+1;
                    }
                }
                cout<<l+1<<endl;
            } else {
                cout<<-1<<endl;
            }
            continue;
        }
        if(ch=='+'){
            pre = sd[k].ff;
            nxt = sd[k].ss;
            sd[pre].ss = k;
            sd[nxt].ff = k;
            a[k]=1;
        }else {
            pre = sd[k].ff;
            nxt = sd[k].ss;
            sd[pre].ss = nxt;
            sd[nxt].ff = pre;
            a[k]=0;
        }
        change(1, 0, N, k);
        change(1, 0, N, pre);
        change(1, 0, N, nxt);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}