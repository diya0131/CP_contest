#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const ll N = 2e5;

const bool te = false;

vector < ll > primes(N+5, 1);

void solve(){
    ll n, k, i, j, t, a, b, q;
    cin>>n;
    if(n==1){
        cout<<1<<endl<<1<<endl;
        return;
    }
    if(n==2){
        cout<<2<<endl<<1 _ 2<<endl;
        return;
    }
    if(n==3){
        cout<<2<<endl<<1 _ 2 _ 2<<endl;
        return;
    }
    if(n==4){
        cout<<3<<endl<<1 _ 2 _ 2 _ 3<<endl;
        return;
    }
    if(n==5){
        cout<<3<<endl<<1 _ 2 _ 2 _ 3 _ 3<<endl;
        return;
    }
    cout<<4<<endl;
    for(i=1;i<=n;i++){
        cout<<i%4+1<<" ";
    }
    cout<<endl;
    
}

int main(){
    int t, i ,j;
    cin>>t;
    primes[1]=0;
    primes[2]=0;
    primes[0]=0;
    for(i=3;i<sqrt(N);i++){
        if(primes[i]){
            j=2*i;
            while(j<N){
                primes[j]=0;
                j+=i;
            }
        }
    }
    while(t--){
        solve();
    }
}