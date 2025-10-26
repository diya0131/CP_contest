#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, k, t, i, su, res, r;
    bool done;
    cin>>n>>k;
    string s;
    res=n;
    cin>>s;
    ll cnt[2];
    cnt[0]=0;
    cnt[1]=0;
    for(i=0;i<n;i++){
        cnt[s[i]-'0']++;
    }
    
    char a, b, c;

    if((n/k)%2){
        // cout<<cnt[0] _ cnt[1]<<endl;
        if(cnt[0]>cnt[1]){
            if(cnt[1]!=(n-k)/2){
                cout<<-1<<endl;
                return;
            }
        }
        else{
            if(cnt[0]!=(n-k)/2){
                cout<<-1<<endl;
                return;
            }
        }
        if(s[0]=='0'){
            a='0';
            b='1';
        }
        else{
            b='0';
            a='1';
        }
        su=0;
        c=a;
        done=false;
        for(i=0;i<n;i++){
            
            if(s[i]==c){
                su++;
                if(su==k){
                    c=a+b-c;
                    su=0;
                }
            }
            else{
                // cout<<"-- "<<i<<endl;
                if(done){
                    // cout<<"done\n";
                    cout<<-1<<endl;
                    return;
                }
                else{
                    done=true;
                    if(su==0){
                        while(s[i]!=c){
                            i++;
                        }
                        res=i-k;
                        i--;
                        su=0;
                    }
                    else{
                        res=i;
                        c=a+b-c;
                        i--;
                        su=0;
                    }
                }
            }
        }
    }
    else{
        if(cnt[0]!=n/2){
            cout<<-1<<endl;
            return;
        }
        if(s[0]=='0'){
            a='0';
            b='1';
        }
        else{
            b='0';
            a='1';
        }
        // cout<<a<<" - "<<b<<endl;
        su=0;
        c=a;
        done=false;
        for(i=0;i<n;i++){
            // cout<<i _ s[i] _ c _ su<<endl;
            if(s[i]==c){
                su++;
                if(su==k){
                    c=a+b-c;
                    su=0;
                }
            }
            else{
                // cout<<"--"<<i _ su _ c<<endl;
                if(done){
                    // cout<<"done\n";
                    cout<<-1<<endl;
                    return;
                }
                else{
                    done=true;
                    if(su==0){
                        while(s[i]!=c){
                            i++;
                        }
                        res=i-k;
                        i--;
                        su=0;
                    }
                    else{
                        res=i;
                        c=a+b-c;
                        i--;
                        su=0;
                    }
                }
            }
        }
    }
    cout<<res<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


