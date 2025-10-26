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
    ll n, k, i, j, res=0, tr;
    cin>>n;
    bool isodd;
    cin>>k;
    tr = k;
    isodd = k%2;
    for(i=1;i<n;i++){
        cin>>k;
        if(isodd!=(k%2)){
            res =1;
        }
    }
    if(res){
        cout<<-1<<endl;
        return;
    }
    k=1;
    for(i=0;i<29;i++) k*=2;
    
    if(!isodd) cout<<31<<endl;
    else cout<<32<<endl;
   
    for(i=0;i<30;i++){
        tr = abs(tr - k);
        
        // cout<<tr _ k<<endl;
        cout<<k<<" ";
        k/=2;
    }
    if(!isodd){
        // cout<<"hey"<<endl;
        // tr = abs(tr - 1);
        // cout<<tr _ "*" _ 1<<endl;;
        cout<<1<<endl;
    } else {
        // tr = abs(tr - 1);
        // cout<<tr _ 1<<endl;;
        // tr = abs(tr - 1);
        // cout<<tr _ "*" _ 1<<endl;;
        cout<<1 _ 1<<endl;
    }
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}