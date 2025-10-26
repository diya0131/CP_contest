
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
    ll n, m, i, j, c, k, res=100, p, su, t, q;
    cin>>n>>c>>k;
    res = c;
    string s;
    cin>>s;
    m=(1 << c);
    ll prev[c];
    ll mat[c][c];
    for(i=0;i<c;i++) prev[i]=-1;
    for(i=0;i<c;i++){
        for(j=0;j<c;j++){
            mat[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        q = s[i]-'A';
        for(j=0;j<c;j++){
            mat[j][q]=max(mat[j][q], q - prev[j]);
        }
    }
    for(i=0;i<c;i++){
        for(j=0;j<c;j++){
            mat[i][j]=max(mat[i][j], n- prev[i]);
        }
    }
    for(i=0;i<m;i++){
        bool can = true;
        q = s[n-1]-'A';
        if((1 << q) & i){
            p=-1;
            su=0;
            t = i;
            while(t>0){
                if(t%2) su++;
                t/=2;
            }
            for(j=0;j<n;j++){
                q = s[j]-'A';
                if((1 << q) & i){
                    p=j;
                }
                test<<j _ p _ q <<endl; 
                if(j>=p+k) {
                    can = false;
                    break;
                }
            
            }
            test<<can _ i _ j _ su _ res<<endl;
            if(can) res=min(res, su);
        }
        
        
    }

    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}