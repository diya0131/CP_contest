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

int main() {
    ll n, i, j, a, b, c, d, e, k;
    pair < int , vector < int > > p;
    vector < pair < int , vector < int > > > res;
    cin>>a>>b>>c>>d>>e;
    for(i=1;i<32;i++){
        k = i;
        p.ff =0;
        p.ss.clear();
        if(k%2){
            p.ff+=a;
            p.ss.pb(0-'A');
        }
        k/=2;
        if(k%2){
            p.ff+=b;
            p.ss.pb(0-'B');
        }
        k/=2;
        if(k%2){
            p.ff+=c;
            p.ss.pb(0-'C');
        }
        k/=2;
        if(k%2){
            p.ff+=d;
            p.ss.pb(0-'D');
        }
        k/=2;
        if(k%2){
            p.ff+=e;
            p.ss.pb(0-'E');
        }
        res.pb(p);
    }
    char ch;
    sort(ALL(res));
    for(i=30;i>=0;i--){
        for(j=0;j<res[i].ss.size();j++){
            ch = -res[i].ss[j];
            cout<<ch;
        }
        cout<<endl;
    }
}