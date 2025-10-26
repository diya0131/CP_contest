#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<

using namespace std;
ll mod = 1000000007;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, k, i, t , j, l, sum, q1, q2, res;
    string s;
    bool can;
    cin>>n>>k;
    q1 = 0;
    q2 = 1;
    

    map < string , ll > mp[2], check;
    for(i=0;i<k;i++){
        cin>>s;
        mp[q1][s]++;
    }
    n--;
    res=k;
    while(n--){
        q2=(q1+1)%2;
        res=0;
        // cout<<"here; " _ n _ q1 _ q2<<endl;
        for(i=0;i<k;i++){
            cin>>s;
            sum =0;
            string tmp1(s.size()-1, ' ');
            string tmp2(s.size()-1, ' ');
            can = false;
            for(j=0;j<s.size()-1;j++){
                tmp1[j]=s[j];
                tmp2[j]=s[j+1];
                if(tmp1[j]!=tmp2[j]) can = true;
            }
            if(mp[q1].find(tmp1)!=mp[q1].end()) {
                sum=(sum+mp[q1][tmp1])%mod;
            }
            
            if(can && mp[q1].find(tmp2)!=mp[q1].end()) {
                sum=(sum+mp[q1][tmp2])%mod;
            }
            mp[q2][s]+=sum;
            res=(res+sum)%mod;
        }
        mp[q1].clear();
        q1=q2;
    }
    
    cout<<res<<endl;

}