#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    map< int, int > tmp1;
    map< int , map< int, int > > tmp2;
    map < int, map< int , map< int, int > > > mp;
    int n, m, i, j, k ,s ;
    cin>>n;
    vector < int > a;
    for(i=0;i<n;i++){
        cin>>k;
        a.pb(k);
    }
    ll same3=0 , same1=0, same2=0, same0=0;
    for(i=0;i<n-2;i++){
        if(mp.find(a[i]) != mp.end()){
            if( mp[a[i]].find(a[i+1]) != mp[a[i]].end() ){
                if(mp[a[i]][a[i+1]].find(a[i+2]) != mp[a[i]][a[i+1]].end()){
                    same3+=mp[a[i]][a[i+1]][a[i+2]];
                    mp[a[i]][a[i+1]][a[i+2]]++;
                    
                }
                else{
                    mp[a[i]][a[i+1]][a[i+2]]=1;
                }
            }
            else{
                mp[a[i]][a[i+1]]=tmp1;
                mp[a[i]][a[i+1]][a[i+2]]=1;
            }
        }
        else{
            mp[a[i]]=tmp2;
            mp[a[i]][a[i+1]]=tmp1;
            mp[a[i]][a[i+1]][a[i+2]]=1;
        }
    }
    tmp2.clear();
    same2=0;
    for(i=0;i<n-2;i++){
        if(tmp2.find(a[i]) != tmp2.end()){
            if( tmp2[a[i]].find(a[i+2]) != tmp2[a[i]].end() ){
                same2+=tmp2[a[i]][a[i+2]];
                tmp2[a[i]][a[i+2]]++;
            }
            else{
                tmp2[a[i]][a[i+2]]=1;
                
            }
        }
        else{
            tmp2[a[i]]=tmp1;
            tmp2[a[i]][a[i+2]]=1;
        }
    }
    tmp2.clear();
    same1=0;
    for(i=0;i<n-2;i++){
        if(tmp2.find(a[i]) != tmp2.end()){
            if( tmp2[a[i]].find(a[i+1]) != tmp2[a[i]].end() ){
                same1+=tmp2[a[i]][a[i+1]];
                tmp2[a[i]][a[i+1]]++;
            }
            else{
                tmp2[a[i]][a[i+1]]=1;
                
            }
        }
        else{
            tmp2[a[i]]=tmp1;
            tmp2[a[i]][a[i+1]]=1;
        }
    }
    tmp2.clear();
    same0=0;
    for(i=1;i<n-1;i++){
        if(tmp2.find(a[i]) != tmp2.end()){
            if( tmp2[a[i]].find(a[i+1]) != tmp2[a[i]].end() ){
                same0+=tmp2[a[i]][a[i+1]];
                tmp2[a[i]][a[i+1]]++;
            }
            else{
                tmp2[a[i]][a[i+1]]=1;
                
            }
        }
        else{
            tmp2[a[i]]=tmp1;
            tmp2[a[i]][a[i+1]]=1;
        }
    }
    // cout<<same0 _ same1 _ same2 _ same3<<endl;
    ll all = same0 + same1 + same2 - 3*same3;


    cout<<all<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}