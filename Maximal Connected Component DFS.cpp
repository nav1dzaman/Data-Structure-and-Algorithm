#include<bits/stdc++.h>
using namespace std;
vector <int> graph[1000000];
vector <int> storing;
int counter=0;
bool visited[5000000];
  vector <int> vv,tmp;
void dfs(int source){
    counter++;
    vv.push_back(source);
    visited[source] = 1;
    for(int i=0;i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0){
             dfs(next);
        }
    }
}
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

   int maxi=0;

   for(int k=1;k<=edges;k++){
        for(int h=1;h<=edges;h++){
            visited[h]=false;
        }
        for(int i=1;i<=edges;i++){
                counter=0;
            if(visited[i]==false){
            visited[i]=true;
               dfs(i);
           maxi=max(maxi,counter);
        }

    }
   }

    cout<<maxi<<endl;
}
