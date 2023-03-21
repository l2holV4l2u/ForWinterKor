#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    long long num,a[810],b[810],sum=0;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>a[i];
    }
    for(int i=0;i<num;i++){
        cin>>b[i];
    }
    sort(a,a+num);
    sort(b,b+num);
    for(int i=0;i<num;i++){
        sum+=(a[i]*b[i]);
    }
    cout<<sum;
    return 0;
}
/*
3
1 3 -5
-2 4 1
*/
