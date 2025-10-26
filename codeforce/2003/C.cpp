#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<
#define test if(te) cout

using namespace std;

const bool te = 1;

const ll N = 1e5;

void solve() {
    int n, i, j, k;
    cin >> n;
    string s;
    cin >> s;
    char ch;
    vector < pair < int, int > > cnt(26);
    for (i = 0;i < 26;i++) cnt[i] = { 0, i };
    for (i = 0;i < n;i++) {
        cnt[s[i] - 'a'].ff++;
    }
    sort(cnt.begin(), cnt.end());
    j = 25;
    for (i = 0;i < n;i += 2) {
        while (cnt[j].ff == 0) {
            j--;
        }
        ch = 'a' + cnt[j].ss;
        s[i] = ch;
        cnt[j].ff--;
    }
    for (i = 1;i < n;i += 2) {
        while (cnt[j].ff == 0) {
            j--;
        }
        ch = 'a' + cnt[j].ss;
        s[i] = ch;
        cnt[j].ff--;
    }
    cout << s << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();

}