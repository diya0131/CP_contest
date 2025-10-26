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

void solve(){
    ll n, m, i, j;
    cin>>n>>m;
    int a[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(n==1 && m==1){
        cout<<-1<<endl;
        return;
    }
    if(n>1){

    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[(i+1)%n][(j+1)%m]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}