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
    int n, i, j, k, t, res=0;
    string s;
    cin>>n>>s;
    pair < int, char > a={0, 'T'}, b={0, 'L'}, c={0, 'I'}, ab, bc;
    for(i=0;i<n;i++){
        if(s[i]==a.ss) a.ff++;
        if(s[i]==b.ss) b.ff++;
        if(s[i]==c.ss) c.ff++;
    }   
    if((a.ff==0)+(b.ff==0)+(c.ff==0)==2){
        cout<<-1<<endl;
        return;
    } 
    if(a.ff>b.ff) swap(a, b);
    if(b.ff>c.ff) swap(b, c);
    if(a.ff>b.ff) swap(a, b);
    // cout<<a.ss _ b.ss _ c.ss <<endl;
    queue < int > q;
    if(a.ff == b.ff){
        for(i=0;i<n;i++){
            if(s[i]==c.ss){
                if(i>0 && s[i-1]!=c.ss){
                    ab = {i, 1};
                    break;
                } 
                if(i+1<n && s[i+1]!=c.ss){
                    ab = {i, 0};
                    break;
                }
            }
        }
        if(ab.ss){
            j=i;
            for(int l=0;l<c.ff - b.ff;l++){
                res+=2;
                q.push(j);
                q.push(j+1);
                j+=2;
            }
        } else{
            j=i+1;
            for(int l=0;l<c.ff - b.ff;l++){
                res+=2;
                q.push(j);
                q.push(j);
            }
        }
    } else{

        for(i=0;i<n;i++){
            if(s[i]==b.ss){
                if(i>0 && s[i-1]!=b.ss){
                    ab = {i, 1};
                    break;
                } 
                if(i+1<n && s[i+1]!=b.ss){
                    ab = {i, 0};
                    break;
                }
            }
        }
        if(ab.ss){
            if(s[i-1]==a.ss){
                j=i;
                for(int l=0;l<b.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j+1);
                    j+=2;
                }
                j=i;
                for(int l=0;l<c.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j+1);
                    j+=2;
                }
            } else {
                j=i;
                for(int l=0;l<b.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j+1);
                    j+=2;
                }
                j=i;
                for(int l=0;l<c.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j);
                }
            }
        } else{
            if(s[i+1]==a.ss){
                j=i+1;
                for(int l=0;l<b.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j);
                }
                j=i+3;
                for(int l=0;l<c.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j);
                }
            } else {
                // cout<<"hey\n";
                j=i+1;
                for(int l=0;l<b.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j);
                }
                j=i+2;
                for(int l=0;l<c.ff - a.ff;l++){
                    res+=2;
                    q.push(j);
                    q.push(j);
                }
            }
        }
    }
    cout<<res<<endl;
    
    while(!q.empty()){
        
        cout<<q.front()<<endl;
        q.pop();
    }
}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}