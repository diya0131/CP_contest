#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

int main(){
  int n;
  cin>>n;
  int i, k, l, t, s=0, q;
  int a[2*n];
  for(i=0;i<2*n;i++){
    cin>>a[i];
  }
  for(i=1;i<2*n-1;i++){
    if(a[i-1]==a[i+1]){
        cout<<i<<endl;
        s++;
    }
  }
  cout<<s<<endl;
}