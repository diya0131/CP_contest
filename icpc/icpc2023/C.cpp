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
const int N = 10000 * 365 + 1;
const int pad = 2000 * 365;
const vector days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int date_to_int(string s) {
    int a[3] = { 0 };
    s += '-';
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            idx++;
        } else {
            a[idx] = a[idx] * 10 + (s[i] - '0');
        }
    }
    vector<int> pre(14, 0);
    for (int i = 0; i < 13; i++) {
        pre[i + 1] = pre[i] + days[i];
    }
    return a[0] * 365 + pre[a[1]] + a[2];
}

string int_to_date(int a) {
    int y = a / 365;
    a %= 365;
    int m = 0;
    if (a == 0) {
        y--;
        m = 12;
        a = 31;
    } else {
        while (a > days[m]) {
            a -= days[m];
            m++;
        }
    }
    string Y = "0000";
    string M = "00";
    string D = "00";
    int i = 3;
    while (y) {
        Y[i] = y % 10 + '0';
        y /= 10;
        i--;
    }
    i = 1;
    while (m) {
        M[i] = m % 10 + '0';
        m /= 10;
        i--;
    }
    i = 1;
    while (a) {
        D[i] = a % 10 + '0';
        a /= 10;
        i--;
    }
    return Y + "-" + M + "-" + D;
}

vector<bool> home(N, 1);
vector<int> cnt(N + 1, 0);

int main() {
    int n, y, d;
    cin >> n >> y >> d;
    string s, t;
    int st, fn;
    int last;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        st = date_to_int(s);
        fn = date_to_int(t);
        st += pad;
        fn += pad;
        for (int j = st; j <= fn; j++) {
            home[j] = 0;
        }
        last = fn;
    }
    cnt[0] = 1;
    for (int i = 0; i < N; i++) {
        cnt[i + 1] = cnt[i] + home[i];
    }
    int ans = last + y * 365 + 1;
    for (int i = 1; i <= 365; i++) {
        int today = i + last;
        bool fail = 0;
        for (int j = 0; j < y; j++) {
            if (cnt[today - 365 * j] - cnt[today - 365 * (j + 1)] < d) {
                ans = min(today - 365 * j + y * 365, ans);
                fail = 1;
                break;
            }
        }
        if (!fail) {
            ans = min(ans, today);
        }
    }
    cout << int_to_date(ans - pad) << endl;
}