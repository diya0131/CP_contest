#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

int main(){
    ll n, i, j, k, s, res=0, l, r;
    cin>>n;
    ll a[n], b[n];
    vector < pair< int, int > > st;
    queue < pair < int, int > > nm;
    pair< int, int > pr, mypr;
    for(i=0;i<n;i++){
        cin>>a[i];
        st.pb(pr);
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    l=0; r=-1;
    for(i=0;i<n;i++){
        // cout<<i<<endl;
        while(!nm.empty() && l<=r){
            cout<<l<<endl;
            pr = nm.front();
            mypr = st[l];
            if(mypr.ff-pr.ff>=i-mypr.ff){
                
                if(pr.ss>=mypr.ss){
                    cout<<"nuhuh: "<<pr.ff _ pr.ss _ l _ mypr.ss<<endl;
                    nm.front().ss -= mypr.ss;
                    
                    l++;

                }
                else{
                    cout<<"nuhuh: "<<pr.ff _ pr.ss _ l _ st[l].ss<<endl;
                    st[l].ss-=pr.ss;
                    nm.pop();
                }
            }
            else break;
        }


        s=b[i];
        while(l<=r && s>0){
            pr = st[r];
            if(pr.ss<=s){
                cout<<"avah: "<<pr.ff _ pr.ss _ s<<endl;
                s-=pr.ss;
                r--;
                res=max(res, i-pr.ff);
            }
            else{
                cout<<"avah: "<<pr.ff _ pr.ss _ s<<endl;
                res=max(res, i-pr.ff);
                pr.ss-=s;
                s=0;
                
                st[r]=(pr);
                cout<<"changed: "<<pr.ff _ pr.ss _ s<<endl;
            }
        }
        k=s;
        
       
        s=a[i];
        // while(!nm.empty() && s>0){
        //     pr=nm.top();
        //     nm.pop();
        //     if(pr.ff)
        //     if(pr.ss<=s){
        //         // cout<<"uguh: "<<pr.ff _ pr.ss _ s<<endl;
        //         s-=pr.ss;
        //         res=max(res, i-pr.ff);
        //     }
        //     else{
        //         // cout<<"uguh: "<<pr.ff _ pr.ss _ s<<endl;
        //         res=max(res, i-pr.ff);
        //         pr.ss-=s;
        //         s=0;
                
        //         nm.push(pr);
        //         // cout<<"changed: "<<pr.ff _ pr.ss _ s<<endl;
        //     }
        // }
        cout<<k _ s<<endl;
        if(s>k){
            pr.ff=i;
            pr.ss=s-k;
            cout<<"nemeh to st: "<<pr.ff _ pr.ss _ (s-k) _ s<<endl;
            r++;
            st[r]=pr;
            cout<<"r: "<<r<<endl;
        }
        else{
            pr.ff=i;
            pr.ss=(k-s);
            cout<<"nemeh to nm: "<<pr.ff _ pr.ss _ (k-s) _ s<<endl;
            nm.push(pr);
        }
    }
    if(l>r){
        cout<<"res" _ res<<endl;
    }
    else{
        cout<<-1<<endl;
    }


}