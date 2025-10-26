#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    string str;
    cin>>str;
    ll c=0, v=0, i, j, y=0, n=0, g=0, k, res=0, x, t ,yt, q;
    for(char ch:str){
        if(ch=='Y') y++;
        else{
            if(ch=='N') n++;
            if(ch=='G') g++;
            if(ch=='A' || ch=='E' || ch == 'I' || ch== 'O' || ch =='U'){
                v++;
            } else{
                c++;
            }
        }
    }
    // cout<<v _ c _ y _ n _ g<<endl;
    for(i=1;i<=v+y;i++){
        j=i;
        if(j>v) yt=y-(j-v);
        else yt = y;
        if(i+j> c+yt){
            continue;
        }
        q = min(min(i+j, c+yt-i-j), min(n, g));
        // cout<<i _ j _ q _ i+2*j+q<<endl;
        res = max(res, i+2*j+q);
            
        
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    solve();
}