#include<bits/stdc++.h>
#include<random>
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
    ll k, n, neg=0, pos=0, s=0, sp=-1, i;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>k;
        a[i]=k;
        if(k==1) pos++;
        else if(k==-1) neg++;
        else sp=i;
    } 
    if(sp==-1){
        ll mn = 0, mx = 0;
        s=0;
        for(i=0;i<n;i++){
            s+=a[i];
            if(s<0) s=0;
            mx=max(s, mx);
        }
        s=0;
        for(i=0;i<n;i++){
            s+=a[i];
            if(s>0) s=0;
            mn=min(s, mn);
        }
        cout<<mx - mn +1<<endl;
        for(i=mn;i<=mx;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    } else {
        ll lmn=0, lmx=0, rmn=0, rmx=0;
        s=0;
        for(i=0;i<sp;i++){
            s+=a[i];
            if(s<0) s=0;
            lmx=max(s, lmx);
        }
        s=0;
        for(i=0;i<sp;i++){
            s+=a[i];
            if(s>0) s=0;
            lmn=min(s, lmn);
        }
        s=0;
        for(i=sp+1;i<n;i++){
            s+=a[i];
            if(s<0) s=0;
            rmx=max(s, rmx);
        }
        s=0;
        for(i=sp+1;i<n;i++){
            s+=a[i];
            if(s>0) s=0;
            rmn=min(s, rmn);
        }
        ll mn = min(lmn, rmn), mx = max(lmx, rmx), spmx=a[sp], spmn=a[sp];
        s=0;
        for(i=sp;i>=0;i--){
            s+=a[i];
            spmx=max(spmx, s);
            spmn=min(spmn, s);
        }
        s=0;
        ll dmx=spmx, dmn=spmn;
        spmx=0;
        spmn=0;
        for(i=sp+1;i<n;i++){
            s+=a[i];
            spmx=max(spmx, s);
            spmn=min(spmn, s);
        }
        spmx+=dmx;
        spmn+=dmn;
        if(mn<spmn){
            ll c=0;
            for(i=mn;i<=mx;i++){
                c++;
            }
            for(i=max(mx+1, spmn);i<=spmx;i++){
                c++;
            }
            cout<<c<<endl;
            for(i=mn;i<=mx;i++){
                cout<<i<<" ";
            }
            for(i=max(mx+1, spmn);i<=spmx;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        } else {
            ll c=0;
            for(i=spmn;i<=spmx;i++){
                c++;
            }
            for(i=max(spmx+1, mn);i<=mx;i++){
                c++;
            }
            cout<<c<<endl;
            for(i=spmn;i<=spmx;i++){
                cout<<i<<" ";
            }
            for(i=max(spmx+1, mn);i<=mx;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
        
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}