#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

int main(){
    ll n, i, j, k, s, res=0;
    cin>>n;
    ll a[n], b[n];
    stack < pair< int, int > > st, nm;
    pair< int, int > pr;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }

    for(i=0;i<n;i++){
        // cout<<i<<endl;
        s=b[i];
        
        while(!st.empty() && s>0){
            pr = st.top();
            st.pop();
            if(pr.ss<=s){
                // cout<<"avah: "<<pr.ff _ pr.ss _ s<<endl;
                s-=pr.ss;
                res=max(res, i-pr.ff);
            }
            else{
                // cout<<"avah: "<<pr.ff _ pr.ss _ s<<endl;
                res=max(res, i-pr.ff);
                pr.ss-=s;
                s=0;
                
                st.push(pr);
                // cout<<"changed: "<<pr.ff _ pr.ss _ s<<endl;
            }
        }
        k=s;
        
       
        s=a[i];
        while(!nm.empty() && s>0){
            pr=nm.top();
            nm.pop();
            if(pr.ff)
            if(pr.ss<=s){
                // cout<<"uguh: "<<pr.ff _ pr.ss _ s<<endl;
                s-=pr.ss;
                res=max(res, i-pr.ff);
            }
            else{
                // cout<<"uguh: "<<pr.ff _ pr.ss _ s<<endl;
                res=max(res, i-pr.ff);
                pr.ss-=s;
                s=0;
                
                nm.push(pr);
                // cout<<"changed: "<<pr.ff _ pr.ss _ s<<endl;
            }
        }
        // cout<<k _ s<<endl;
        if(s>k){
            pr.ff=i;
            pr.ss=s-k;
            // cout<<"nemeh to st: "<<pr.ff _ pr.ss _ (s-k) _ s<<endl;
            st.push(pr);
        }
        else{
            pr.ff=i;
            pr.ss=(k-s);
            // cout<<"nemeh to nm: "<<pr.ff _ pr.ss _ (k-s) _ s<<endl;
            nm.push(pr);
        }
    }
    if(st.empty()){
        cout<<res<<endl;
    }
    else{
        cout<<-1<<endl;
    }


}