#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

const ll N=200000*29+1;
// const ll N=200;


int main() {
    // BOOST
    int n, k, i, j, s, t;
    
    cin>>n>>k;
    s=n*(k-1);
    vector < bitset<N> > bs(30, bitset<N>(0));
    bitset<N> tmp;
    int sqn=sqrt(n);
    for(int i=1;i<=sqn;i++){
        // cout<<i<<endl;
        t=i*i;
        bs[0].set(t, 1);
        for(j=1;j<k;j++){
            tmp=bs[j-1];
            tmp<<=t;
            bs[j]=bs[j] | tmp;
        }
    }
    if(bs[k-1][s]==1){
        cout<<"YES\n";
        for(int i=1;i<=sqn;i++){
            if()
        }
    }
    else cout<<"NO\n";
    
}