#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0; i<n;i++) cin>>a[i];
    vector< int > prefix(n);
    int s=0;
    for(int i=0; i<n;i++){
        s+=a[i];
        prefix[i]=s;
    }

    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }





    for(int i=0; i<n;i++) {
        cout<<prefix[i]<<" ";
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        if(l==0){
            cout<<prefix[r]<<endl;
        }
        else {
            cout<<prefix[r]-prefix[l-1]<<endl;
        }
    }
}


