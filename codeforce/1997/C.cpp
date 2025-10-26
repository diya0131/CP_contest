#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve() {
    ll n, k, i, j, cnt = 0, res = 0;
    cin >> n;
    string s;
    cin >> s;
    stack < int > st, ab;
    for(i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
        } else if(s[i]==')'){
            if(cnt==0){
                s[ab.top()]='(';
                ab.pop();
                cnt++;
            } else {
                cnt --;
            }
        } else {
            if(cnt > 0){
                s[i]=')';
                cnt--;
                ab.push(i);
            } else {
                s[i]='(';
                cnt++;
            }
        }
    }
    for(i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        } else {
            res+=i-st.top();
            st.pop();
        }
    }
    cout << res << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}