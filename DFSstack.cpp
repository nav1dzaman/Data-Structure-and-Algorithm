#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10000];
bool visited[500000];

void DFS_IT(int start){
    stack<int> S;
    S.push(start);
    visited[start]=true;

    while(!S.empty()){

        int ans=S.top();
        S.pop();
        cout<<ans<<endl;
        for(auto i:graph[ans]){
           if(visited[i]==false){
            S.push(i);
            visited[ans]=true;
           }
        }

    }
}

int main(){
 int node,edges;
     cin>>node>>edges;
     for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);  //undirected graph
     }

    DFS_IT(1);
    
   // cout<<4<<endl;
     
}