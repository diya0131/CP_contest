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
    ll n, k, i, q, j, x, y, s;
    cin>>n>>q;
    string a, b;
    cin>>a>>b;
    vector < vector < ll > >  acnt(n+1, vector < ll >(26, 0)),  bcnt(n+1, vector < ll >(26, 0));
    vector < ll > acn(26, 0), bcn(26, 0);
    for(i=0;i<n;i++){
        acn[a[i]-'a']++;
        bcn[b[i]-'a']++;
        acnt[i+1]=acn;
        bcnt[i+1]=bcn;
    }
    while(q--){
        cin>>x>>y;
        s=0;
        for(i=0;i<26;i++){
            test<<"val:" _ i _ x _ y _ acnt[y][i] _ acnt[x-1][i] _ bcnt[y][i] _ bcnt[x-1][i]<<endl;
            s+=abs(acnt[y][i] - acnt[x-1][i] - bcnt[y][i] + bcnt[x-1][i]);
            test<<s<<endl;
        }
        test<<"s:" _ s<<endl;
        cout<<s/2<<endl;
    }
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}