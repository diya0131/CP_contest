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

void solve() {
    ll n, i, j, s, k, t, p, mx, sz, v;
    cin>>n;
    for(i=2;i<n;i++){
        cout<<"?" _ 1 _ i<<endl;
        cout.flush();
        cin>>t;
        if(t==-1) return;
        if(t==0) break;
    }
    
    k=i;
    vector < vector < ll > > path(k);
    path[1].pb(k);
    j=1;
    mx=1;
    for(i=k+1;i<n;i++){
        do{
            if(j==k) j=1;
            sz=path[j].size();
            if(sz==0) v=j;
            else v = path[j][sz-1];
            if(v>mx){
                cout<<"?" _ j _ i<<endl;
                cout.flush();
                cin>>t;
                if(t==-1){
                    return;
                }
                if(t) j++;
                else{
                    path[j].pb(i);
                    mx=max(v, mx);
                    break;
                }
                
            } else j++;
        }while(1);
        
        
    }
    vector < ll > par(n, 0);
    for(i=1;i<k;i++){
        par[i]=0;
        p=i;
        for(j=0;j<path[i].size();j++){
            par[path[i][j]]=p;
            p=path[i][j];
        }
    }
    cout<<"! ";
    for(i=1;i<n;i++) cout<<par[i]<<" ";
    cout<<endl;
    cout.flush();
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}