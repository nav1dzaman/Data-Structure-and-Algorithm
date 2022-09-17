#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1000050];
bool visited[1000050];
int distanc[1000050];
int ways[1000050];
void bfs(int start){

    queue<int>Q;
    visited[start]=true;
    distanc[start]=0;
    ways[start]=1;
    Q.push(start);

    while(!Q.empty()){
        int parent=Q.front();
        Q.pop();

        for(int i=0;i< graph[parent].size();i++){
            int current=graph[parent][i];

            if(visited[current]==false){

                visited[current]=true;

                Q.push(current);
            }

            if(distanc[current]>distanc[parent]+1){
                distanc[current]=distanc[parent]+1;
                ways[current]=ways[parent];
            }
            else if(distanc[current]==distanc[parent]+1){
                ways[current]+=ways[parent];
            }
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
       int x,y;
       cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1;i<=e;i++){
        distanc[i]=INT_MAX;
    }
   int s;
   cin>>s;
   bool ans=false;
   bfs(s);
   for(int i=1;i<=e;i++){
      if(ways[i]>1){
        ans=true;
        break;
      }
   }
   if(ans){
    cout<<"YES"<<endl;

   }
   else cout<<"NO"<<endl;


}
