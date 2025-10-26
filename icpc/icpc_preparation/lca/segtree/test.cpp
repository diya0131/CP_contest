
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define PLL pair < ll, ll >
#define _ <<" "<<


using namespace std;

int main() {
    int n;
    vector < int > arr;
    for(int i=0;i<5;i++) {
        cin>>n;
        arr.pb(n);
    }
    for(auto k: arr){
        cout<<k<<endl;
    }
}