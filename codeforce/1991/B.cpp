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

void solve(){
    ll n, k, i, j, t, res=0, q, p;
    cin>>n;
    k=(1<<31);
    k--;
    ll a[n];
    
    vector < ll > b(30, 0);
    // 0 optional
    // 1 must
    // 2 must not
    a[0]=0;
    for(i=1;i<n;i++){
        cin>>t;
        q=0;
        p=1;
        for(j=0;j<30;j++){
            if(t%2){
                if(b[j]==2) {
                    res = 1;
                }
                if(b[j]==0){
                    // cout<<"hey" _ i _ q<<endl;
                    a[i-1]+=p;
                }
                b[j]=1;
                q+=p;
            } else {
                if(b[j]==1) b[j]=2;
                else b[j]=0;
            }
            t/=2;
            p*=2;
        }
        a[i]=q;
    }
    if(res){
        cout<<-1<<endl;
        return;
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}