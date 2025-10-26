#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

vector < pair < int, int > > res[101]; 

void solve(ll n){
    ll n1=0, t, x, nval, q=1, i, j, tq, a, b;
    t=n;
    // test<<n<<endl;
    while(t>0){
        t/=10;
        n1++;
        q*=10;
    }
    q/=10;
    nval =0;
    // test<<"q: "<<q<<endl;
    for(x=1;x<=6;x++){
        nval =0;
        tq=q;
        t=n;
        // test<<"x: "<<x<<endl;
        for(i=0;i<x;i++){
            // cout<<nval _ "*" _  i<<endl;
            nval=10*nval + (t/tq)%10;
            tq/=10;
            if(tq==0){
                tq=q;
            }
           
        }
        //  cout<<nval _ i<<endl;
        
        if((nval - x)%(n-n1)==0){
            a = (nval - x)/(n-n1);
            b = a*n-nval;
            // test<<"n: added"<<a _ b<<endl;
            if(a>0 && b>0 && a<=10000 && b<=10000) res[n].pb({a, b});
        }
        

    }
    
    // test<<"done\n";
    
}

void solveaf(){
    int n;
    cin>>n;
    if(n==1){
        cout<<9999<<endl;
        for(int i=1;i<=9999;i++){
            cout<<i+1 _ i<<endl;
        }
    } else {
        cout<<res[n].size()<<endl;
        for(int i=0;i<res[n].size();i++){
            cout<<res[n][i].ff _ res[n][i].ss<<endl;
        }
    }
}

int main(){
    int t;
    
    for(int i=2;i<=100;i++){
        solve(i);
    }
    
    cin>>t;
    while(t--){
        solveaf();
    }
}