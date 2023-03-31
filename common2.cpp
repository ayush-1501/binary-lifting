#include<bits/stdc++.h>
using namespace std;
const int MAX=17;
vector<int>parent(1e5),level(1e5);
int table[MAX][10000];

void dfs(int node,int l,vector<vector<int>>&g){
   level[node]=l;
   for(int child:g[node]){
    parent[child]=node;
    dfs(child,l+1,g);
   }
}

//using binary lifting
void build(int n){
   //setting first parent
   for(int i=0;i<=n;i++){
    table[0][i]=parent[i];
   } 

   //storing pow(2,i) parent
   for(int i=1;i<=MAX;i++){
    for(int j=2;j<=n;j++){
      table[i][j]=table[i-1][table[i-1][j]];
    }
   }
}

int lca(int u,int v){
    //if level of v is less than level of u
    if(level[u]>level[v]){
        swap(u,v);
    }
    

    //doing binary lifting
    //lifting v difference k times
    int k=level[v]-level[u];
    for(int i=MAX;i>=0;i--){
        int mask=1<<i;
        if((mask&k)>0){
            v=table[i][v];
        }
    }

    if(u==v)return u;

    //else after having same level keep searching for the common parent upwards
    while(u!=v){
        u=parent[u];
        v=parent[v];
    }
    return u;
}


int main(){
    int n;cin>>n;
    vector<vector<int>>g(n+1);

    //graph input
    for(int i=1;i<=n;i++){
       int count;cin>>count;
       for(int j=0;j<count;j++){
         int x;cin>>x;
         g[i].push_back(x);
       }
    }

    //dfs call for storing parent and level
    dfs(1,1,g);
    build(n+1);

    //queries for lca of u and v
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
}


//inputs
/*
9
2 2 3
2 4 5
2 6 7
0
0
1 8
1 9
0
0
3
8 7
4 9
5 2
*/

/*
output
3
1
2
*/