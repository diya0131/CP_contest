#include<bits/stdc++.h>
#include<chrono>
#include<random>
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

mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

const bool TEST = 0;
const ll M = 1e9 + 7, p = 100019;
void solve() {
    ll n, m, q, k, i, j, s = 0, ch, p, v, nw, sz, idx, su=0;
    cin >> n >> m >> q;
    vector < ll > a(n), b(m);
    for (i = 0;i < n;i++) {
        cin >> k;
        k--;
        a[i] = k;
    }
    vector < set< ll > > st(n);
    map < ll, ll > lst;
    map <  ll, ll >::iterator it;
    vector < ll > resa(n), pref(n, 0);
    v = 0;
    p = a[0];
    resa[0] = 0;
    ll cns = rng()%10000000, cns1=rng()%10000000;
    pref[0]=a[0];
    // cout<<cns _ cns1<<endl;
    for (i = 1;i < n;i++) {
        pref[i]=a[i]+pref[i-1];
        v += (p + cns1) * (a[i] + cns);
        // cout<<"resa" _ i _ v _ p _ a[i]<<endl;
        resa[i] = v;
        p = a[i];
    }
    for (i = 0;i < m;i++) {
        cin >> k;
        k--;
        b[i] = k;
        st[k].insert(i);
    }
    for (i = 0;i < n;i++) {
        if (!st[i].empty()) lst[*st[i].begin()] = i;
    }

    v = 0;
    it = lst.begin();
    test << (*it).ff _(*it).ss << endl;
    p = (*it).ss;
    su=p;
    it++;
    for (;it != lst.end();it++) {
        v += ((p + cns1) * ((*it).ss + cns));
        p = (*it).ss;
        su+=p;
    }
    sz = lst.size();
    test << "0 " _ sz _ resa[sz - 1] _ v _ su _ pref[sz-1]<< endl;
    if (v == resa[sz - 1] && (*lst.begin()).ss == a[0] && su==pref[sz-1]) cout << "YA\n";
    else cout << "TIDAK\n";
    while (q--) {
        cin >> j >> k;
        // for(auto ite=lst.begin(); ite!=lst.end();ite++) cout<<(*ite).ff _ " - " _  (*ite).ss<<endl;
        k--;
        j--;
        ch = 0;
        nw = 0;
        p = b[j];
        if (p == k) {
            sz = lst.size();
            test << q _ " res " _ sz _ resa[sz - 1] _ v << endl;
            if (v == resa[sz - 1] && (*lst.begin()).ss == a[0] && su==pref[sz-1]) cout << "YA\n";
            else cout << "TIDAK\n";
            continue;
        }
        if (*(st[p].begin()) == j) {
            idx = *st[p].begin();
            it = lst.find(idx);
            if (it != lst.begin()) v -= ((*prev(it)).ss + cns1) * (p + cns);
            if (next(it) != lst.end()) v -= ((*next(it)).ss + cns) * (p + cns1);
            if (it != lst.begin() && next(it) != lst.end()) v += ((*prev(it)).ss + cns1) * ((*next(it)).ss + cns);
            st[p].erase(j);
            lst.erase(it);
            su-=p;
            if (!st[p].empty()) {
                idx = *st[p].begin();
                lst[idx] = p;
                su+=p;
                it = lst.find(idx);
                if (it != lst.begin()) v += ((*prev(it)).ss + cns1) * (p + cns);
                if (next(it) != lst.end()) v += ((*next(it)).ss + cns) * (p + cns1);
                if (it != lst.begin() && next(it) != lst.end()) v -= ((*prev(it)).ss + cns1) * ((*next(it)).ss + cns);
            }
            test << "dropped" _ v _ p << endl;

        } else st[p].erase(j);

        b[j] = k;
        // st[k].insert(j);
        if (st[k].empty()) {
            st[k].insert(j);
            idx = j;
            lst[idx] = k;
            su+=k;
            it = lst.find(idx);
            if (it != lst.begin()) v += ((*prev(it)).ss + cns1) * (k + cns);
            if (next(it) != lst.end()) v += ((*next(it)).ss + cns) * (k + cns1);
            if (it != lst.begin() && next(it) != lst.end()) v -= ((*prev(it)).ss + cns1) * ((*next(it)).ss + cns);

            test << "new " _ v  _ idx << endl;
        } else {
            if (*(st[k].begin()) > j) {
                idx = *st[k].begin();
                it = lst.find(idx);
                if (it != lst.begin()) v -= ((*prev(it)).ss + cns1) * (k + cns);
                test << "added1 - " _ idx _ v _((*prev(it)).ss + cns1) _(k + cns) << endl;
                if (next(it) != lst.end()) v -= ((*next(it)).ss + cns) * (k + cns1);
                test << "added2 - " _ idx _ v _(*it).ff _(*it).ss << endl;
                if (it != lst.begin() && next(it) != lst.end()) v += ((*prev(it)).ss + cns1) * ((*next(it)).ss + cns);
                st[k].insert(j);
                test << "added - " _ idx _ v _(*it).ff _(*it).ss << endl;
                lst.erase(it);
                

                idx = j;
                lst[idx] = k;
                it = lst.find(idx);
                if (it != lst.begin()) v += ((*prev(it)).ss + cns1) * (k + cns);
                if (next(it) != lst.end()) v += ((*next(it)).ss + cns) * (k + cns1);
                if (it != lst.begin() && next(it) != lst.end()) v -= ((*prev(it)).ss + cns1) * ((*next(it)).ss + cns);

                test << "added" _ v << endl;

            } else st[k].insert(j);
        }
        sz = lst.size();
        test << q _ " res " _ sz _ resa[sz - 1] _ v _ su _ pref[sz-1]<< endl;
        if (v == resa[sz - 1] && (*lst.begin()).ss == a[0] && su==pref[sz-1]) cout << "YA\n";
        else cout << "TIDAK\n";
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}