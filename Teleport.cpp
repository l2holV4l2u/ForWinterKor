#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll num,p,q,k,dat[6],e,sum=0,temp,t,dis[11][11][11][11][11][11];
    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>p>>q;
    t=num*p*q*num*p*q;
    while(t--){
        temp=0;
        for(int j=0;j<6;j++){
            cin>>dat[j];
        }
        cin>>e;
        dis[dat[0]][dat[1]][dat[2]][dat[3]][dat[4]][dat[5]]=e;
    }
    cin>>k;
    temp=0;
    k--;
    for(int i=0;i<3;i++){
        cin>>dat[i];
    }
    while(k--){
        for(int i=0;i<3;i++){
            cin>>dat[i+3];
        } 
        sum+=dis[dat[0]][dat[1]][dat[2]][dat[3]][dat[4]][dat[5]];
        for(int i=0;i<3;i++){
            dat[i]=dat[i+3];
        }
    }
    cout<<sum;
    return 0;
}
/*
1 3 2
1 1 1 1 1 1 0
1 1 1 1 1 2 7
1 1 1 1 2 1 9
1 1 1 1 2 2 3
1 1 1 1 3 1 6
1 1 1 1 3 2 1
1 1 2 1 1 1 5
1 1 2 1 1 2 0
1 1 2 1 2 1 9
1 1 2 1 2 2 3
1 1 2 1 3 1 6
1 1 2 1 3 2 1
1 2 1 1 1 1 5
1 2 1 1 1 2 7
1 2 1 1 2 1 0
1 2 1 1 2 2 3
1 2 1 1 3 1 6
1 2 1 1 3 2 1
1 2 2 1 1 1 5
1 2 2 1 1 2 7
1 2 2 1 2 1 9
1 2 2 1 2 2 0
1 2 2 1 3 1 6
1 2 2 1 3 2 1
1 3 1 1 1 1 5
1 3 1 1 1 2 7
1 3 1 1 2 1 9
1 3 1 1 2 2 3
1 3 1 1 3 1 0
1 3 1 1 3 2 1
1 3 2 1 1 1 5
1 3 2 1 1 2 7
1 3 2 1 2 1 9
1 3 2 1 2 2 3
1 3 2 1 3 1 6
1 3 2 1 3 2 0
8
1 3 2
1 2 1
1 2 2
1 1 1
1 1 2
1 2 1
1 2 2
1 3 1
*/
