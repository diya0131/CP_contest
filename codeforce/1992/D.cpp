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
    ll i, j, s=0, k, t, n, m=0, p, w;
    string str;
    char ch;
    bool islog=true, res;
    cin>>n>>m>>k;
    t=-1;
    p=-1;
    w = -1;
    cin>>str;
    res=true;
    for(i=0;i<n;i++){
        ch=str[i];
        if(islog){
            if(i>t+m){
                if(w==i-1){
                    t=w;
                    islog=false;
                    
                    if(k==0) {
                        test<<"run out\n";
                        res = false;
                        }
                        k--;
                } else res = false;
            }
        }
        if(ch=='W'){
            if(islog){
                w=i;
            } else {
                t++;
               
                if(k==0) {
                        test<<"run out\n";
                        res = false;
                        }
                        k--;
            }
        } else if ( ch== 'L'){
            islog = true;
            t=i;
        } else {
            if(!islog) res=false;
        }
    }
    if(islog){
        if(i>t+m){
            if(w==i-1){
                t=w;
                islog=false;
                if(k==0) {
                        test<<"run out\n";
                        res = false;
                        }
                k--;

            } else res = false;
        }
    }
    
    if(res) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}