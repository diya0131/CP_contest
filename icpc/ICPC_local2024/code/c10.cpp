#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<

using namespace std;
ll mod = 1000000007;

int main(){
    ll n, m, k, i, j, s, t, mid;
    cin>>n>>m>>k;
    
    if(k>n*m-1){
        cout<<"IMPOSSIBLE"<<endl;

        return 0;
    }
    if(m%2){
        if(k<n+m-2){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<"POSSIBLE"<<endl;

        return 0;
        
    }
    
    if(n%2){
        
        if(k<n+m-2){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<"POSSIBLE"<<endl;
        
        
    
        return 0;
    }
    if(k<n+m-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<"POSSIBLE"<<endl;
        


}