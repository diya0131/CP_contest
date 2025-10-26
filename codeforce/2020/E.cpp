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
const ll M=1e9+7;
const ll inv=285700002;

void solve() {
    ll n, i, j, k, s=0, skv=0, t, a, b, c, d, m4=10000,a1, l;
    cin>>n;
    vector < ll > arr(n), p(n), pow(20);
    pow[0]=1;
    for(i=1;i<20;i++) pow[i]=pow[i-1]*2;
    ll res=0;
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=0;i<n;i++) cin>>p[i];
    for(j=0;j<=10;j++){
        a=0;
        b=1;
        for(i=0;i<n;i++){
            if(arr[i] & pow[j]){
                c=p[i];
                d=m4-c;
                c=(c*inv)%M;
                d=(d*inv)%M;
                a1=(a*d%M+b*c%M)%M;
                b=(a*c%M+b*d%M)%M;
                a=a1;
            }
        }
        t=(a * pow[j*2])%M;
        if (a) test<<"kv" _ j _ a <<endl;
        res=(res+t)%M;
    }
    int prob[4], tmp[4];
    for(j=0;j<=10;j++){
        for(l=j+1;l<=10;l++){
            prob[0]=1;
            prob[1]=0;
            prob[2]=0;
            prob[3]=0;
            for(i=0;i<n;i++){
                c=p[i];
                d=m4-c;
                c=(c*inv)%M;
                d=(d*inv)%M;
                k=0;
                if(arr[i] & pow[j]) k+=2;
                if(arr[i] & pow[l]) k++;
               
                for(int i1=0;i1<4;i1++){
                    tmp[i1]=(prob[i1]*d%M + prob[i1 ^ k] * c%M)%M;
                }
                for(int i1=0;i1<4;i1++){
                    prob[i1]= tmp[i1];
                }
                
            }
            t=(prob[3]*pow[j+l]*2)%M;
            if(prob[3]) test<<"add " _ j _ l _ prob[3]<<endl;
            res=(res+t)%M;
        }
    }
    cout<<(res%M+M)%M<<endl;
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
}