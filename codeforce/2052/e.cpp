#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {

}

int main() {
    string s;
    cin >> s;
    ll n = s.size(), i, j, k = 0, c = 0, p = 0, num = 0, res = 0, l, r, idx, ch, t;
    bool going = true, sign = true, inv = false;
    vector < pair < ll, pair < ll, ll > > >nums;
    vector < pair < ll, ll > > a(n);
    for (i = 0;i < n;i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (!going) {
                c++;
                going = 1;
                p = i;
            }
            a[i] = { c, i - p };
            num = num * 10 + (s[i] - '0');
        } else {
            if (!sign) num = -num;
            nums.pb({ num, {p , i - 1} });
            going = 0;
            res += num;
            num = 0;
            if (s[i] == '=') {
                inv = true;
                sign = false;
            } else {
                sign = ((s[i] == '+') ^ inv);
            }
        }
    }
    if (!sign) num = -num;
    nums.pb({ num, {p, i - 1} });
    going = 0;
    res += num;

    if (res == 0) {
        cout << "Correct\n";
        return 0;
    }

    ll pow[15];
    pow[0] = 1;
    for (i = 1;i < 15;i++) pow[i] = 10 * pow[i - 1];
    for (i = 0;i < n;i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))continue;
        idx = a[i].ff;
        l = nums[idx].ss.ff;
        r = nums[idx].ss.ss;
        if (l == r) continue;
        if (i == l && s[i + 1] == '0') continue;
        k = r - i;
        ch = nums[idx].ff - (nums[idx].ff / pow[k + 1] * pow[k] + nums[idx].ff % pow[k]);


        for (j = -1;j < l - 1;j++) {
            if (j >= 0 && s[j] >= '0' && s[j] <= '9') idx = a[j].ff;
            else idx = a[j + 1].ff;
            if (nums[idx].ss.ss - nums[idx].ss.ff == 9) continue;
            if (s[i] == '0' && nums[idx].ss.ff - 1 == j) continue;
            k = nums[idx].ss.ss - j;
            num = abs(nums[idx].ff);
            num = (num / pow[k] * pow[k + 1] + (s[i] - '0') * pow[k] + num % pow[k]);
            if (nums[idx].ff < 0) num = -num;
            num = nums[idx].ff - num;
            if (res - ch - num == 0) {
                for (l = 0;l < n;l++) {
                    t = 0;
                    if (i <= j) {
                        if (l == j) cout << s[i];
                        else {
                            if (l >= i) t++;
                            if (l >= j) t--;
                            cout << s[l + t];
                        }
                    } else {
                        if (l == j + 1) cout << s[i];
                        else {
                            if (l >= j + 1) t--;
                            if (l > i) t++;
                            cout << s[l + t];
                        }
                    }
                }
                cout << endl;
                return 0;
            }
        }
        for (j = r + 1;j < n;j++) {
            if ((s[j] >= '0' && s[j] <= '9')) idx = a[j].ff;
            else idx = a[j + 1].ff;
            if (s[i] == '0' && nums[idx].ss.ff - 1 == j) continue;
            if (nums[idx].ss.ss - nums[idx].ss.ff == 9) continue;
            k = nums[idx].ss.ss - j;
            num = abs(nums[idx].ff);
            num = (num / pow[k] * pow[k + 1] + (s[i] - '0') * pow[k] + num % pow[k]);
            if (nums[idx].ff < 0) num = -num;
            num = nums[idx].ff - num;
            if (res - ch - num == 0) {
                for (l = 0;l < n;l++) {
                    t = 0;
                    if (i <= j) {
                        if (l == j) cout << s[i];
                        else {
                            if (l >= i) t++;
                            if (l >= j) t--;
                            cout << s[l + t];
                        }
                    } else {
                        if (l == j + 1) cout << s[i];
                        else {
                            if (l >= j + 1) t--;
                            if (l > i) t++;
                            cout << s[l + t];
                        }
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }

    for (int idx = 0;idx < nums.size();idx++) {
        l = nums[idx].ss.ff;
        r = nums[idx].ss.ss;
        for (i = l;i <= r;i++) {
            if (i == l && s[i + 1] == '0') continue;
            for (j = l-1;j <= r;j++) {
                if (s[i] == '0' && j == -1) continue;
                num = abs(nums[idx].ff);
                if (i <= j) {
                    num = num / pow[r - i + 1] * pow[r - i + 1] + num % pow[r - i] / pow[r - j] * pow[r - j + 1] + (s[i] - '0') * pow[r - j] + num % pow[r - j];
                } else {
                    num = num / pow[r - j] * pow[r - j] + num % pow[r - j] / pow[r - i + 1] * pow[r - i] + (s[i] - '0') * pow[r - j - 1] + num % pow[r - i];
                }
                if (nums[idx].ff < 0) num = -num;
                num = nums[idx].ff - num;

                if (res - num == 0) {
                    for (l = 0;l < n;l++) {
                        t = 0;

                        if (i <= j) {
                            if (l == j) cout << s[i];
                            else {
                                if (l >= i) t++;
                                if (l >= j) t--;
                                cout << s[l + t];
                            }
                        } else {
                            if (l == j + 1) cout << s[i];
                            else {
                                if (l >= j + 1) t--;
                                if (l > i) t++;
                                cout << s[l + t];
                            }
                        }

                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Impossible\n";
    return 0;
}