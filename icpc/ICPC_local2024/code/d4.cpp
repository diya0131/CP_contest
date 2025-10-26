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
    vector < pair< ll, ll > > st;
    queue < pair < ll, ll > > nm;
    pair< ll, ll > pr, mypr;
    for(i=0;i<n;i++){
        cin>>a[i];
        st.pb(pr);
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    l=0; r=-1;
    for(i=0;i<n;i++){
        cout<<i<<endl;
        r++;
        pr.ff=i;
        pr.ss=a[i];
        st[r]=pr;
        cout<<l _ r <<endl;
        while(!nm.empty() && l<=r){
           
            pr = nm.front();
            mypr = st[l];
            cout<<mypr.ff-pr.ff <<" haha "<< i-mypr.ff<<endl;
            if(mypr.ff-pr.ff<=i-mypr.ff){
                res=max(res, mypr.ff-pr.ff );
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
            cout<<l _ r _ mypr.ff-pr.ff _ i-mypr.ff<<endl;
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
        
        cout<<k<<endl;
        // s=a[i];
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
        // cout<<k _ s<<endl;
        // if(s>k){
        //     pr.ff=i;
        //     pr.ss=s-k;
        //     cout<<"nemeh to st: "<<pr.ff _ pr.ss _ (s-k) _ s<<endl;
        //     r++;
        //     st[r]=pr;
           
        // }
        if(k>0){
            pr.ff=i;
            pr.ss=(k);
            cout<<"nemeh to nm: "<<pr.ff _ pr.ss _ (k)<<endl;
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