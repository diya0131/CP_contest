//https://cses.fi/problemset/task/1143
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const int N = 2e5+5;

int st[4*N];

void build(vector < int >&a, ll v, ll tl, ll tr){
    if(tl==tr){
        st[v]=a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(a, 2*v, tl, tm);
    build(a, 2*v+1, tm+1, tr);
    st[v]= max(st[2*v], st[2*v+1]);
}

int get(ll v, ll tl, ll tr, ll val){
    if(tl==tr){
        st[v]-=val;
        return tl;
    }
    int tm = (tl+tr)/2, k;
    if(st[2*v]>=val) k= get(2*v, tl, tm, val);
    else k= get(2*v+1, tm+1, tr, val);
    st[v]=max(st[2*v], st[2*v+1]);
    return k;
}

void printt(int n){
    for(int i=1;i<4*n;i++){
        cout<<i _ st[i]<<endl;
    }
}



int main(){
    int n, m, i, j, k, s;
    // freopen("input.txt", "r", stdin);
    cin>>n>>m;
    vector < int > a;
    for(i=0;i<n;i++){
        cin>>k;
        a.pb(k);
    }
    // cout<<"here: "<<endl;
    build(a, 1, 0, n-1);
    // printt(n);
    while(m--){
        cin>>k;
       
        if(st[1]<k) cout<<0<<" ";
        else{
            cout<<get(1, 0, n-1, k)+1<<" ";
        }
    }
    cout<<endl;
}