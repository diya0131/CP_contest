#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, i, j, t, k, s, l, r, a, b, c, m, all, sub, mi, li, ri;
    cin>>n;
   
    cout<<"xor "<<1 _ n<<endl;
    cout.flush();
    cin>>all;

    if(all==0){
        l=1;
        r=1;
        for(i=0;i<60;i++){
            cout<<"xor "<<l _ r<<endl;
            cout.flush();
            cin>>k;
            if(k!=0) {
                a=k;
                break;
            }
            r=(r+1)*2-1;
        }
        l=a+1;
        r=n;
        while(l<=r){
            m=(l+r)/2;
            cout<<"xor "<<a+1 _ m<<endl;
            cout.flush();
            cin>>k;
            if(k==0){
                l=m+1;
            }else{
                if(k==(all ^ a)) r=m-1;
                else{
                    b=k;
                    c=(all ^ b ^ a);
                    break;
                }
            }
        }
        
        cout<<"ans "<<a _ b _ c<<endl;
        cout.flush();
        return;
    } 
    l=1;
    r=n;
    while(l<=r){
        m=(l+r)/2;
        cout<<"xor "<<1 _ m<<endl;
        cout.flush();
        cin>>k;
        if(k==0){
            l=m+1;
        }else{
            if(k==all) r=m-1;
            else{
                sub=k;
                c=(all ^ k);
                li=l;
                ri=m;
                while(li<=ri){
                    mi=(li+ri)/2;
                    cout<<"xor "<<1 _ mi<<endl;
                    cout.flush();
                    cin>>k;
                    if(k==0){
                        li=mi+1;
                    }else{
                        if(k==sub) ri=mi-1;
                        else{
                            a=(sub ^ k);
                            b=k;
                            cout<<"ans "<<a _ b _ c<<endl;
                            cout.flush();
                            return;
                        }
                    }
                }
                a=sub;
                sub=(all ^ a);
                li=m+1;
                ri=r;
                while(li<=ri){
                    mi=(li+ri)/2;
                    cout<<"xor "<<m+1 _ mi<<endl;
                    cout.flush();
                    cin>>k;
                    if(k==0){
                        li=mi+1;
                    }else{
                        if(k==sub) ri=mi-1;
                        else{
                            b=(sub ^ k);
                            c=k;
                            cout<<"ans "<<a _ b _ c<<endl;
                            cout.flush();
                            return;
                        }
                    }
                }
                break;
            }
        }
    }
    cout<<"ans "<<a _ b _ c<<endl;
    cout.flush();
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

