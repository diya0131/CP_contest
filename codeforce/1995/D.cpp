
#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

ll get(ll a, ll b){
    test<<"get" _ a _ b<<endl;
    ll s=0;
    while(a*a<=b){
        s++;
        a=a*a;
    }
    test<<"get" _ a _ b _ s<<endl;
    return s;
}

ll get1(ll a, ll b){
    test<<"get1" _ a _ b<<endl;
    ll s=0;
    while(a>b){
        s++;
        b=b*b;
    }
    test<<"get1" _ a _ b _ s<<endl;
    return s;
}

void solve(){
    ll n, m, i, j, x, s=0, c=0, res=0, q, p, k;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];
    q=0;
    for(i=1;i<n;i++){
        test<<a[i-1] _ a[i]<<endl;
        if(a[i]==1){
            if(a[i-1]>1){
                cout<<-1<<endl;
                return;
            } else continue;
        }
        if(a[i-1]==1) continue;
        if(a[i-1]<=a[i]){
            k = get(a[i-1], a[i]);
            if(q<=k) p=0;
            else p=q-k;
        } else {
            k = get1(a[i-1], a[i]);
            p = k+q;
        }
        test<<i _ p<<endl;
        res+=p;
        q=p;
    }
    test<<"res: ";
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}