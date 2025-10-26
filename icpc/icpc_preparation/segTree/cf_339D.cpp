#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ALL(a) a.begin(), a.end()

using namespace std;



vector < ll > tree;

void update(ll v, ll tl, ll tr, ll pos, ll val, bool odd){
    if(tl==tr){
        tree[v] = val;
    }
    else{
        ll tm=(tl+tr)/2;
        if(pos<=tm) update(2*v, tl, tm, pos, val, !odd);
        else update(2*v+1, tm+1, tr, pos, val, !odd);

        if(odd) tree[v]= tree[2*v] | tree[2*v+1];
        else tree[v] = tree[2*v] ^ tree[2*v+1];
    }
}



int main(){
    ll n, m, i, j, k, s, t, ma, p;
    cin>>n>>m;
    ma= 1<<n;
    for(i=0;i<4*ma;i++){
        tree.pb(0);
    }
    bool odd=n%2;
    
    for(i=0;i<ma;i++){
        cin>>k;
        update(1, 0, ma-1, i, k, odd);
    }
    // cout<<tree[1]<<endl;
    for(i=0;i<m;i++){
        cin>>p>>k;
        update(1, 0, ma-1, p-1, k, odd);
        cout<<tree[1]<<endl;
    }

}