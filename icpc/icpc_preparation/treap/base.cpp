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


struct item{
    ll key;
    ll prior;
    item *l, *r;
    item (ll key) : key(key), prior(rand()), l(NULL), r(NULL) { }
    item (ll key, ll prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item* pitem;

void printTreap(pitem root, int depth = 0) {
    if (!root) {
        for (int i = 0; i < depth; ++i) cout << "    ";
        cout<<"NULL\n";
        return; 
    }
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << "Key: " << root->key << ", Prior: " << root->prior << endl;
    if (root->l || root->r) {
        for (int i = 0; i < depth; ++i) cout << "    ";
        cout << "L-> \n";
        printTreap(root->l, depth + 1);
    for (int i = 0; i < depth; ++i) cout << "    ";
        cout << "R-> \n";
        printTreap(root->r, depth + 1);
    }
}


void split(pitem t, ll x, pitem& l, pitem& r){
    if(!t){
        l = r = nullptr;
        return;
    }
    if(t->key < x){
        split(t->r, x, l, r);
        t->r = l;
        l = t;
    } else {
        split(t->l, x, l, r);
        t->l = r;
        r=t;
    }
}


// void insert (pitem & t, pitem it) {
//     if (!t)
//         t = it;
//     else if (it->prior > t->prior)
//         split (t, it->key, it->l, it->r),  t = it;
//     else
//         insert (t->key <= it->key ? t->r : t->l, it);
// }

void insert(pitem& t, pitem it){
    if(!t) {
        t=it;
        return;
    }
    if(t->prior > it->prior){
        if(it->key<=t->key) insert(t->l, it);
        else insert(t->r, it);
    } else{
        pitem l = nullptr, r = nullptr;
        split(t, it->key, l, r);
        t=it;
        it->l = l;
        it->r = r;
    }
}

void merge(pitem& t, pitem l, pitem r) {
    if(l->key < r->key){
        t=r;
        merge(r->l, l, r->l);
    } else {
        t=l;
        merge(l->r, l->r, r);
    }
}

int main() {
    pitem head = new item(0, LLONG_MAX);
    pitem arr[10];
    for(int i=0;i<10;i++){
        pitem it=new item(i+1);
        arr[i]=it;
        insert(head, arr[i]);
    }
    printTreap(head);
    for(int i=0;i<10;i++){
        cout<<i _ arr[i]->key _ arr[i]->prior<<endl;
        delete arr[i];
    }
    // cout<<head->key<<endl;
    // pitem l = nullptr, r = nullptr;
    // for( int i=0; i<2;i++){
    //     item it(i+1, i+1);
    //     insert(head, &it);
    // }
    // cout<<"printing..\n" _ head->prior  _ head->key<< endl;
    
    
}