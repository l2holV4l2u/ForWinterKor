#include<bits/stdc++.h>

using namespace std;

int row,col,q,flag,visit[30][30],coor[4]={-1,1,0,0},path[110][2];
string tab[30],str;

bool isvalid(int cr,int cc){
    return cr>=0&&cr<row&&cc>=0&&cc<col;
}

void dfs(int ind,int cr,int cc){
    path[ind][0]=cr,path[ind][1]=cc;
    if(ind==str.length()-1){
        for(int i=0;i<str.length();i++){
            cout<<path[i][0]+1<<" "<<path[i][1]+1<<"\n";
        }
        flag=1;
    }
    if(flag){
        return;
    }
    for(int i=0;i<4;i++){
        if(isvalid(cr+coor[i],cc+coor[3-i])&&tab[cr+coor[i]][cc+coor[3-i]]==str[ind+1]&&!visit[cr+coor[i]][cc+coor[3-i]]){
            visit[cr+coor[i]][cc+coor[3-i]]=1;
            dfs(ind+1,cr+coor[i],cc+coor[3-i]);
            visit[cr+coor[i]][cc+coor[3-i]]=0;
        }
    }
}

void solve(){
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=tolower(str[i]);
        }
    }
    flag=0;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(str[0]==tab[i][j]){
                visit[i][j]=1;
                dfs(0,i,j);
                visit[i][j]=0;
            }
        }
    }
    if(!flag){
        cout<<"No Matching Word\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>tab[i];
        for(int j=0;j<col;j++){
            if(tab[i][j]>='A'&&tab[i][j]<='Z'){
                tab[i][j]=tolower(tab[i][j]);
            }
        }
    }
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}
/*
3 5
TAEPE
TULAR
STOPW
2
PEATT
HELLOWORLD
*/
