#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff firts
#define ss second
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, x, y, s=0, i, j, mi, ma;
    ll l=-1, r;
    cin>>n;
    ll a[n], b[n];
    pair < ll, ll > li[n];
    m=-1;
    ll q=1;
    

    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i]!=-1) {
            if(l==-1) l=i;
            r=i;
        }
    }
    if(l==-1){
        for(i=0;i<n;i++){
            cout<<i%2+1<<" ";
        }
        cout<<endl;
        return;
    }
    for(i=l-1;i>=0;i--){
        b[i]=a[l]*((l-i)%2+1);
    }
    for(i=r+1;i<n;i++){
        b[i]=a[r]*((i-r)%2+1);
    }
    for(i=l+1;i<=r;i++){
        if(a[i]==-1){
            if(b[i-1]!=1){
                b[i]=b[i-1]/2;
            }
        }
        else{
            
            if(a[i]!=b[i-1]/2){
                if(a[i]==1) q=2;
                else q=a[i]/2;
                j=i-1;
                while(b[j]!=q && a[j]==-1){
                    b[j]=q;
                    if(q==1){
                        q*=2;
                    }
                    else q/=2;
                    j--;
                }
                if(b[j]!=q){
                    cout<<-1<<endl;
                    return;
                }
            }
            
        }
    }
    for(i=0;i<n;i++){
        cout<<b[i]<<" ";
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