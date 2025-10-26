#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

vector < vector < ll > > path;

ll res;

void solve() {
    ll n, i, j, k, s=0, t, m, u, v, cnt;
    path.clear();
    
    cin>>n;
    res=-n;
    vector < ll > vc;
    ll ch[n], gch[n];
    for(i=0;i<n;i++){
        ch[i]=0;
        gch[i]=0;
        path.pb(vc);
    }
    for(i=0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        path[u].pb(v);
        path[v].pb(u);
    }
    for(i=0;i<n;i++){
        if(path[i].size()==1) s++;
    }
    for(i=0;i<n;i++){
        cnt=0;
        
        for(j=0;j<path[i].size();j++){
            k=path[i][j];
            
            if(path[k].size()==2){
                u=(path[k][0]+path[k][1]-i);
                if(path[u].size()>1) cnt++;
            }
        }
        // cout<<i _ cnt<<endl;
        ch[i]=cnt;
        // res=max(res, cnt);
    }

    for(i=0;i<n;i++){
        cnt =0;
        for(j=0;j<path[i].size();j++){
            k=path[i][j];
            if(path[k].size()==3){
                u=0;
                for(int l =0;l<3;l++){
                    if(path[k][l]!=i){
                        t=path[k][l];
                        u=max(u, ch[t]+1);
                    }
                }
            }
        }
    }

    cout<<s+res<<endl;
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}