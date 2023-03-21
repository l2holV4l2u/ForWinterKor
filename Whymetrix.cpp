#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

ll q,tab[100][2][2]={0};
    
void solve(){
    ll num,mat[2][2]={0},tm[2][2];
    cin>>num;
    mat[0][0]=mat[1][1]=1;
    num--;
    for(int i=0;i<32;i++,num/=2){
        if(!(num%2)){
            continue;
        }
        memset(tm,0,sizeof(tm));
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int m=0;m<2;m++){
                    tm[j][k]+=(mat[j][m]*tab[i][k][m]);
                    tm[j][k]%=1000000007;
                }
            }
        }
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                mat[j][k]=tm[j][k];
            }
        }
    }
    cout<<mat[0][0]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>q;
    tab[0][0][0]=tab[0][0][1]=tab[0][1][0]=1;
    for(int i=1;i<32;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int m=0;m<2;m++){
                    tab[i][j][k]+=(tab[i-1][j][m]*tab[i-1][k][m]);         
                    tab[i][j][k]%=1000000007;
                }
            }
        }
    }
    while(q--){
        solve();
    }
    return 0;
}
