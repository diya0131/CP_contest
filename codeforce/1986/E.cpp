#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, i, k, s=0, j, t, odd=0, tmp, p, q ;
    cin>>n>>k;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];
    map < ll , multiset< ll > > mp;
    multiset< ll > st;
    for(i=0;i<n;i++){
        mp[a[i]%k].insert(a[i]/k);
    }
    // cout<<"res: ";
    for(auto ite = mp.begin();ite!=mp.end();ite++){
        st = ite->ss;
        if(st.size()%2) {
            odd++;
            i=0;
            tmp=0;
            k=*st.begin();
            for(auto it = st.begin(); it!=st.end(); it++){
                if(i%2==0){
                    tmp+=*it-k;
                }
                k=*it;
                i++;
            }
            i=0;
            p=0;
            q=tmp;
            k=*st.begin();
            for(auto it = st.begin(); it!=st.end(); it++){
                if(i%2){
                    p+=(*it)-k;
                }
                else{
                    tmp-=*it-k;
                    // cout<<p _ tmp<<endl;
                    q=min(q, p+tmp);
                }
                k=*it;
                i++;
            }
            s+=q;
        }
        else{
            i=0;
            for(auto it = st.begin(); it!=st.end(); it++){
                if(i%2){
                    s+=*it-k;
                }
                else{
                    k=*it;
                }
                i++;
            }
        }
       
    }
    if(odd>1) {
        cout<<-1<<endl;
        return;
    }
    if(odd==1 && n%2==0){
        cout<<-1<<endl;
        return;
    }
    cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}