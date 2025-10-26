#include<bits/stdc++.h>
#include<string.h>
 
using namespace std;

int main(){
    queue < int > a;
    int n;
    cin>>n;
    a.push(n);
    cout<<a.front();
    a.front()++;
    cout<<a.front();



}