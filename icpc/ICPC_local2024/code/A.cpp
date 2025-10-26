#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<

using namespace std;
ll mod = 1000000007;

int main(){
    ll n, k, i, t , j, l, sum, q1, q2;
    string s;
    bool can ;
    cin>>n>>k;
    q1=0;
    q2 = 1;
    vector < string > str[2];
    
    vector < int > p[2];
    for(i=0;i<k;i++){
        cin>>s;
        str[q1].pb(s);
        str[q2].pb("");
        p[q1].pb(1);
        p[q2].pb(0);
    }
    n--;
    while(n--){
        cout<<"here; " _ n<<endl;
        q2=(q1+1)%2;
        for(i=0;i<k;i++){
            cin>>s;
            sum =0;
            // cout<<i<<endl;
            for(j=0;j<k;j++){

                if(p[q1][j]!=0){

                    can = true;
                    for(l=0;l<str[q1][j].size();l++){
                        if(s[l]!=str[q1][j][l]){
                            can = false;
                            break;
                        }
                    }
                
                    // cout<<j _ can _ p[q1][j]<<endl;
                    if(can) sum += p[q1][j];
                }
            }
            // cout<<"sum: " _ sum<<endl;
            str[q2][i]=s;
            p[q2][i]=sum;
        }
        q1=q2;
    }
    ll res =0;
    for(i=0;i<n;i++){
        cout<<p[q1][i]<<" ";
        res += p[q1][i];
    }
    cout<<res<<endl;

}