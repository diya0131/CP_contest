#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, k, t, i, su, res, r;
    bool done;
    cin>>n>>k;
    string s, sub;
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
        if(min(cnt[0], cnt[1])!=(n-k)/2){
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(cnt[0]!=n/2){
            cout<<-1<<endl;
            return;
        }
    }
    

    a=s[0];
    b='0'+'1'-a;
    su=0;
    c=a;
    done=false;
    for(i=0;i<s.size();i++){
        if(s[i]==c){
            su++;
            if(su==k){
                c=a+b-c;
                su=0;
            }
        }
        else{
            if(done){
                // cout<<"done\n";
                cout<<-1<<endl;
                return;
            }
            else{
                done=true;
                if(su==0){
                    r=0;
                    while(i<s.size() && s[i]!=c){
                        r++;
                        i++;
                    }
                    if(r>k){
                        // cout<<"hmm\n";
                        cout<<-1<<endl;
                        return;
                    }
                    sub= s.substr(0, i-k);
                    reverse(sub.begin(), sub.end());
                    // cout<<s<<endl;
                    s+=sub;
                    // cout<<s<<endl;
                    res=i-k;
                    i--;
                    su=0;
                }
                else{
                    sub= s.substr(0, i);
                    reverse(sub.begin(), sub.end());
                    // cout<<s<<endl;
                    s+=sub;
                    // cout<<s<<endl;
                    res=i;
                    c=a+b-c;
                    i--;
                    su=0;
                }
            }
        }
    }
    cout<<res<<endl;

}

int main(){
    int e;
    cin>>e;
    while(e--){
        solve();
    }
}


