#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, x, y, m, i, j, t, k;
    
    string s;
    cin>>s;
    n=s.size();
    ll num0=0, num1=0, inv0 = 0, inv1=0 ,l =0, res=0;
    map < int , vector < int > > mp;
    vector < int > tmp;
    vector < int >::iterator it;
    mp[0].pb(-1);

    vector < int > nor;
    vector < pair<int, int> > inv;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            num0++;
            inv1++;
        }
        else {
            num1++;
            inv0++;    
        }
        nor.pb(num0-num1);
    }
       
    for(i=0;i<n;i++){
        if(s[i]=='('){
            num0++;
            inv1++;
        }
        else {
            num1++;
            inv0++;    
        }
        // cout<<l _ num0 _ num1 _ inv1 _ inv0<<endl;
        while(num0 - num1 - 2*inv1 + 2*inv0<0){
            if(l!=0){
                k = nor[l-1];
                cout<<"l: "<<l _ i _ k<<endl;
                if(l<i){
                    for(it = mp[k].begin(); it!=mp[k].end(); it++) {
                        cout<<*it<<" ";
                    }
                    cout<<endl;
                    it = lower_bound(mp[k].begin(), mp[k].end(),l-1);
                    t= mp[k].size() - (it - mp[k].begin());
                    cout<<"added: "<< t-1 _ *it<<endl;
                    res+= t-1;
                }
            }

            if(s[l]=='('){
                inv1--;
            }
            else{
                inv0--;
            }
            l++;
        }
        // cout<<l _ num0 _ num1 _ inv1 _ inv0<<endl;

        if(mp.find(num0-num1)==mp.end()){
            mp[num0-num1]=tmp;
            mp[num0-num1].pb(i);
        }
        else{
            mp[num0-num1].pb(i);
        }
        

        
    
        // cout<<res<<endl;
    }
    while(l<n){
        cout<<"l: "<<l _ i _ k _ num0 - num1 - 2*inv1 + 2*inv0<<endl;
        if(num0 - num1 - 2*inv1 + 2*inv0>=0){
            k = nor[l-1];
            
            if(l<i){
                for(it = mp[k].begin(); it!=mp[k].end(); it++) {
                    cout<<*it<<" ";
                }
                cout<<endl;
                it = lower_bound(mp[k].begin(), mp[k].end(),l-1);
                t= mp[k].size() - (it - mp[k].begin());
                cout<<"added: "<< t-1 _ *it<<endl;
                res+= (t-1);
            }
        }
        if(s[l]=='('){
            inv1--;
        }
        else{
            inv0--;
        }
        l++;
        
    }
    cout<<"res: "<<res<<endl;
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}