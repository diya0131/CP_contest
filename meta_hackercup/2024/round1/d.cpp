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
const ll mx2 = 21;

const ll M = 998244353;

ll pow2[mx2];

void seta(string& str, pair < ll, ll > pos, ll k){
    ll i=pos.ss, p=pos.ff, n=str.size(), c=i-p+1, v, all;
    if (c == 1) {
        str[i]='0'+k;
        return;
    } else {
        if (i + 2 < n && str[i + 2] == '0'){
            v=k%15;
            if(v<10) {
                str[i]='0'+v;
                str[i-1]='1';
            }else {
                str[i]='0'+v-9;
                str[i-1]='2';
            }
            all=15;
            i=i-2;
            while(i>=p){
                v=(k%(all*2));
                if(v==0) v=all*2;
                if(v>all) str[i]='2';
                else str[i]='1';
                if(all<k) all*=2;
                i--;
            }
        }
        else {
            if (i + 1 < n) {
                if (str[i + 1] <= '6') {
                    all=1;
                    while(i>=p){
                        v=(k%(all*2));
                        if(v==0) v=all*2;
                        if(v>all) str[i]='2';
                        else str[i]='1';
                        if(all<k) all*=2;
                        i--;
                    }
                }
                else {
                    all=1;
                    str[i]='1';
                    i--;
                    while(i>=p){
                        v=(k%(all*2));
                        if(v==0) v=all*2;
                        if(v>all) str[i]='2';
                        else str[i]='1';
                        if(all<k) all*=2;
                        i--;
                    }
                }
            } else {
                v=k%15;
                if(v<10) {
                    str[i]='0'+v;
                    str[i-1]='1';
                }else {
                    str[i]='0'+v-9;
                    str[i-1]='2';
                }
                all=15;
                i=i-2;
                while(i>=p){
                    v=(k%(all*2));
                    if(v==0) v=all*2;
                    if(v>all) str[i]='2';
                    else str[i]='1';
                    if(all<k) all*=2;
                    i--;
                }
            }
        }
    }
}

void solve() {
    string str;
    ll n, i, j, k, s = 0, res, v, c = 0, p = 0;
    cin >> str >> k;
    n = str.size();
    vector < ll > ch;
    vector < pair< ll, ll> > pos;
    for (i = 0;i < n;i++) {
        if (str[i] == '?') {
            if (c == 0) p = i;
            c++;
        } else {
            i--;
            if (c == 1) {
                if (i + 2 < n && str[i + 2] == '0') {
                    if (p > 0) {
                        if (str[p - 1] == '2') v = 6;
                        else v = 9;
                    } else v = 9;
                } else {
                    if (i + 1 < n) {
                        
                        if (str[i + 1] <= '6') v = 2;
                        else v = 1;
                    } else {
                        if (p > 0) {
                            if (str[p - 1] == '2') v = 6;
                            else v = 9;
                        } else v = 9;
                    }
                }
            } else {
                if (i + 2 < n && str[i + 2] == '0') v = pow2[min(mx2 - 1, c - 1)] / 2 * 15;
                else {
                    if (i + 1 < n) {
                        if (str[i + 1] <= '6') v = pow2[min(mx2 - 1, c)];
                        else v = pow2[min(mx2 - 1, c - 1)];
                    } else v = pow2[min(mx2 - 1, c - 1)] / 2 * 15;
                }
            }
            i++;
            if (v > 1) {
                ch.push_back(v);
                pos.push_back({p, i-1});
            }
            c = 0;
        }
    }
    if (c > 0) {
        i--;
        if (c == 1) {
                if (i + 2 < n && str[i + 2] == '0') {
                    if (p > 0) {
                        if (str[p - 1] == '2') v = 6;
                        else v = 9;
                    } else v = 9;
                } else {
                    if (i + 1 < n) {
                        
                        if (str[i + 1] <= '6') v = 2;
                        else v = 1;
                    } else {
                        if (p > 0) {
                            if (str[p - 1] == '2') v = 6;
                            else v = 9;
                        } else v = 9;
                    }
                }
            } else {
                if (i + 2 < n && str[i + 2] == '0') v = pow2[min(mx2 - 1, c - 1)] / 2 * 15;
                else {
                    if (i + 1 < n) {
                        if (str[i + 1] <= '6') v = pow2[min(mx2 - 1, c)];
                        else v = pow2[min(mx2 - 1, c - 1)];
                    } else v = pow2[min(mx2 - 1, c - 1)] / 2 * 15;
                }
            }
            i++;
            if (v > 1) {
                ch.push_back(v);
                pos.push_back({p, i-1});
            }
    }
    // for (i = 0;i < ch.size();i++) cout << ch[i] _ pos[i].ff _ pos[i].ss << endl;
    ll all=1, resa=1;
    for(i=ch.size()-1;i>=0;i--){
        all*=ch[i];
        v=k%ch[i];
        if(v==0) v=ch[i];
        seta(str, pos[i], ch[i]-v+1);
        k=k/ch[i]+1;
        // if(k==1) break;
    }
    // ll st=i;
    // for(i=0;i<st;i++) seta(str, pos[i], ch[i]);
    vector < ll > dp(n+1, 0);
    dp[0]=1;
    for(i=0;i<n;i++){
        v=0;
        if(str[i]=='0') dp[i+1]=dp[i-1];
        else{
            v=dp[i];
            if(i>0 && str[i-1]!='0' && (str[i-1]-'0')*10+(str[i]-'0')<=26){
                v=(v+dp[i-1])%M;
            }
            dp[i+1]=v;
        }
        // cout<<i _ dp[i+1]<<endl;
    }
    cout<<str _ dp[n]<<endl;
    
}   

int main() {
    // BOOST
    ll p = 1;
    for (ll i = 0;i < mx2;i++) {
        pow2[i] = p;
        p *= 2;
    }
    freopen("substitution_cipher_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}