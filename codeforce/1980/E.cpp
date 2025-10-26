#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m, i, j, s, ro, co;
    cin>>n>>m;
    int a[n][m], b[n][m], r[n*m], c[n*m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
            r[a[i][j]-1]=i;
            c[a[i][j]-1]=j;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>b[i][j];
    }
    for(i=0;i<n;i++){
        ro=r[b[i][0]-1];
        for(j=1;j<m;j++){
            if(r[b[i][j]-1]!=ro){
                // cout<<i _ j _ ro<<endl;
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(i=0;i<m;i++){
        co=c[b[0][i]-1];
        for(j=1;j<n;j++){
            if(c[b[j][i]-1]!=co){
                // cout<<j _ i<<co<<endl;
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


