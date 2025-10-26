#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

bool comp(int x, int y){
    return x>y;
}

void solve(){
    int n, f, k, i, j, s, t;
    cin>>n>>f>>k;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    if(n==k) cout<<"YES"<<endl;
    else{
        t=a[f-1];
        sort(a, a+n, comp);
        
        if(a[k]<t) cout<<"YES"<<endl;
        else{
            
            if(a[k-1]>t) cout<<"NO"<<endl;
            else cout<<"MAYBE"<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


