#include<bits/stdc++.h>

using namespace std;

int row,col,ar,ac,br,bc,cr,cc,cd,coor[4]={-1,1,0,0},mini=INT_MAX;
int dista[1010][1010]={0},distb[1010][1010]={0},visita[1010][1010]={0},visitb[1010][1010]={0};
string tab[1010];
    
bool isvalid(int cr,int cc){
    return cr>=0&&cr<row&&cc>=0&&cc<col;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>tab[i];
        for(int j=0;j<col;j++){
            if(tab[i][j]=='A'){
                ar=i,ac=j;
            }
            else if(tab[i][j]=='B'){
                br=i,bc=j;
            }
        }
    }
    queue <tuple <int,int,int>> q;
    q.push({ar,ac,0});
    while(q.size()){
        tie(cr,cc,cd)=q.front();
        q.pop();
        dista[cr][cc]=cd;
        visita[cr][cc]=1;
        for(int i=0;i<4;i++){
            if(isvalid(cr+coor[i],cc+coor[3-i])&&tab[cr+coor[i]][cc+coor[3-i]]!='#'&&!visita[cr+coor[i]][cc+coor[3-i]]){
                visita[cr+coor[i]][cc+coor[3-i]]=1;
                q.push({cr+coor[i],cc+coor[3-i],cd+1});
            }
        }
    }
    q.push({br,bc,0});
    while(q.size()){
        tie(cr,cc,cd)=q.front();
        q.pop();
        distb[cr][cc]=cd;
        visitb[cr][cc]=1;
        for(int i=0;i<4;i++){
            if(isvalid(cr+coor[i],cc+coor[3-i])&&tab[cr+coor[i]][cc+coor[3-i]]!='#'&&!visitb[cr+coor[i]][cc+coor[3-i]]){
                visitb[cr+coor[i]][cc+coor[3-i]]=1;
                q.push({cr+coor[i],cc+coor[3-i],cd+1});
            }
        }
    }
    /*for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<dista[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<distb[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(!visitb[ar][ac]){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(tab[i][j]=='C'&&visita[i][j]&&visitb[i][j]){
                mini=min(dista[i][j]+distb[i][j],mini);
                //cout<<i<<" "<<j<<" "<<dista[i][j]+distb[i][j]<<endl;
            }
        }
    }
    cout<<(mini ? mini:-1);
    return 0;
}
/*
5 5
A....
.##.#
##...
.#...
C#..B
*/
