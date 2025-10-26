#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

// ll lcm(ll x, ll y){
//     ll a = x, b =y;
//     while(a!=0 && b!=0){
//         if(a>b) a=a%b;
//         else b=b%a;
//     }
//     return x*y/(a+b);
// }

void solve(){
    int n, m, res=0, k=1, i, s;
    cin>>n;
    int a[n];
    
    for(i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    bool divisible = true;
    for(i = 0; i < n; i++){
       
        if(a[n-1]%a[i])
        {
            divisible = false;
            break;
        }
        
    }
   
    if(divisible){
        m=a[n-1];
        ll sq = sqrt(m);
        for(i=1;i<=sq;i++){
            if(m%i==0){
                
                if(*lower_bound(a, a+n, i)!=i){
                    s=0;
                    k=1;    
                    for(int j=0;j<n-1;j++){
                        if(i % a[j] == 0) {
                            k=lcm(k, a[j]);
                            s++;
                        }
                    }
                   
                    if(k==i) res = max(s, res);
                }
                if(*lower_bound(a, a+n, m/i)!=m/i){
                    s=0;
                    k=1;
                    for(int j=0;j<n-1;j++){
                        if((m/i) % a[j] == 0) {
                           
                            k=lcm(k, a[j]);
                           
                            s++;
                        }
                    }
                    if(k==(m/i)) res = max(s, res);
                }
            }
        }
        cout<<res<<endl;
    }
    else{
        cout<<n<<endl;
    }
    

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}