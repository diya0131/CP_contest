#include<bits/stdc++.h>
#define _ <<" "<<

using ll = long long;
using namespace std;

void solve(){
    ll n, i, j, k, s=0, s1, s2;
    cin>>n;
    vector< vector< ll > > h(n, vector< ll > (n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>h[i][j];
        }
    }
    vector< ll > a(n), b(n), h1(n, -1), c1(n, -1), t(n, 0);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    bool eq, ih, baga;
    for(i=0;i<n-1;i++){
        eq = false;
        ih=false;
        baga=false;
        for(j=0;j<n;j++){
            if(h[i][j]==h[i+1][j]){
                eq = true;
            }
            if(h[i][j]+1==h[i+1][j]){
                ih = true;
            }
            if(h[i][j]==h[i+1][j]+1){
                baga = true;
            }
        }
        if(eq){
            if(ih && baga){
                cout<<-1<<endl;
                // cout<<"h hey\n";
                return;
            }
            if( ih || baga){
                if(ih){
                    if(h1[i]==1){
                        cout<<-1<<endl;
                        // cout<<"h hmm\n";
                        return;
                    }
                    h1[i]=0;
                    h1[i+1]=1;
                } else{
                    if(h1[i]==0){
                        cout<<-1<<endl;
                        // cout<<"h haha\n" _ i;
                        return;
                    }
                    h1[i]=1;
                    h1[i+1]=0;
                }
            } else{
                if(h1[i]==-1) h1[i+1]=-1;
                else h1[i+1] = 1 - h1[i];
            }
        }
    }
    for(i=0;i<n-1;i++){
        eq = false;
        ih=false;
        baga=false;
        for(j=0;j<n;j++){
            if(h[j][i]==h[j][i+1]){
                eq = true;
            }
            if(h[j][i]+1==h[j][i+1]){
                ih = true;
            }
            if(h[j][i]==h[j][i+1]+1){
                baga = true;
            }
        }
        if(eq){
            if(ih && baga){
                cout<<-1<<endl;
                // cout<<"hor HEY\n";
                return;
            }
            if( ih || baga){
                if(ih){
                    if(c1[i]==1){
                        cout<<-1<<endl;
                        // cout<<"hor hmm\n";
                        return;
                    }
                    c1[i]=0;
                    c1[i+1]=1;
                } else{
                    if(c1[i]==0){
                        cout<<-1<<endl;
                        // cout<<"hor haha\n";
                        return;
                    }
                    c1[i]=1;
                    c1[i+1]=0;
                }
            } else{
                if(c1[i]==-1) c1[i+1]=-1;
                else c1[i+1] = 1 - c1[i];
            }
        }
    }
    
    s+=calc()
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}