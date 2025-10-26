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



void solve() {
    ll n, m, k, i, j;
    cin>>n>>m;
    string s;
    char ch[5]={'n', 'a', 'r', 'e', 'k'};
    vector < ll > a(5, -10), b(5), c(5);
    ll res=0;
    a[0]=0;
    for(i=0;i<n;i++){
        for(j=0;j<5;j++) {
            b[j]=a[j];
            c[j]=j;
        }
        cin>>s;
        for(j=0;j<s.size();j++){
            bool in=false;
            for(int l=0;l<5;l++){
                if(s[j]==ch[l]){
                    in=true;
                    break;
                }
            }
            if(in){
                
                for(int l=0;l<5;l++){
                    if(s[j]==ch[c[l]]){
                        c[l]=(c[l]+1)%5;
                        if(c[l]==0) {
                            b[l]+=10;
                            // if(l==0) cout<<j _ "+10" _ l<<endl;
                        }
                    } 
                    // if(l==0) cout<<j _ "-1" _ l<<endl;
                    b[l]--;
                }
            }
        }
        for(j=0;j<5;j++){
            k=c[j];
            a[k]=max(a[k], b[j]);
        }
        
    }
    res=max(0LL, a[0]);
    // cout<<a[0]<<endl;
    for(i=1;i<5;i++){
        // cout<<a[i]<<endl;
        
        res=max(res, a[i]);
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}