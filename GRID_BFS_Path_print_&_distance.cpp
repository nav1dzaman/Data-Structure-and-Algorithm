#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <sstream>
#include <deque>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;
typedef long long  ll;
typedef long long int lli;
typedef long double ld;
#define io ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define READ_WRITE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define prina(a) for(auto x : a) cout << x << " "; cout << endl
void inv(vector <lli> &v,lli n){
for(lli i=0;i<n;i++){lli x;cin>>x;v.push_back(x);}}
void ina(lli arra[],lli n){for(lli i=0;i<n;i++)cin>>arra[i];}
#define test int T; cin>>T; while(T--)
#define lcm(a,b)  (a*(b/__gcd(a,b)))
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define mp make_pair
#define ln cout<<endl
#define sz(x) ((int) x.size())
#define all(v) v.begin(), v.end()
#define vi vector <lli>
#define deb cout<<"DEBUG"<<endl
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
  const char* comma = strchr (names + 1, ',');
  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
lli MX=100;
lli lev[1000][1000];
lli m,n;
lli dis[1000][1000];
map <pair<lli,lli>,pair<lli,lli>> parent;
bool vs[1000][1000];
char st[1000][1000];
lli dx[]={1,-1,0, 0};
lli dy[]={0, 0,1,-1};
lli cx,cy;
bool ans=false;
map<pair<lli,lli>,lli> turn;
lli lefty=-1,righty=-1;
void bfs(lli fx,lli fy) /// starting position
{
  lli hu=1;
    lli i,v,x,y,md=0;
    queue <pair<lli,lli>> q;
    vs[fx][fy]=1;
  
    q.push({fx,fy});
    while(!q.empty()){
        auto pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<4;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            if(x<0||x>=n||y<0||y>=m)continue; 
            if(vs[x][y]==0 && st[x][y]=='.'){ 
                q.push({x,y});
                vs[x][y]=1;
               dis[x][y]=dis[fx][fy]+1;
               parent[{x,y}]={fx,fy};
               if(turn[{x,y}]==1){
                  lefty=x;
                  righty=y;
               }
               
            }
        }

    } 
   
  }
    
void pathprint(lli x,lli y)
{
    vector<pair<lli,lli>> path;
    lli v=dis[lefty][righty]-1;
     path.push_back({x,y});
     map<pair<lli,lli>,lli> pr;
    while(v--){ 

    
      if(pr[{parent[{x,y}].first,parent[{x,y}].second}]==0){
         path.push_back({parent[{x,y}].first,parent[{x,y}].second});
         pr[{parent[{x,y}].first,parent[{x,y}].second}]=1;
      }
      
       x=parent[{x,y}].first;
       y=parent[{x,y}].second;

       if(pr[{x,y}]==0){
        path.push_back({x,y});
         pr[{x,y}]=1;
      }

    }
     
    reverse(path.begin(), path.end());
    lli aa=cx,bb=cy;
    for(lli i=0;i<sz(path);i++){
      cout<<path[i].first<<" "<<path[i].second<<endl;
    }
    
}


int main()
{
  #ifndef ONLINE_JUDGE
  READ_WRITE
  #endif
   
  
  cin>>n>>m;
 
 
  for(lli i=0;i<n;i++){
    for(lli j=0;j<m;j++){
      cin>>st[i][j];
      if(st[i][j]=='A'){  
        cx=i;
        cy=j;
      }
    }
  }
  for(lli j=0;j<m;j++){
    if(st[0][j]=='.'){
      turn[{0,j}]=1;
    }
    else if(st[n-1][j]=='.'){
      turn[{n-1,j}]=1;
    }
  }
    for(lli i=0;i<n;i++){
    if(st[i][0]=='.'){
      turn[{i,0}]=1;
    }
    else if(st[i][m-1]=='.'){
      turn[{i,m-1}]=1;
    }
  }
 
  bfs(cx,cy);
  if(lefty==-1 && righty==-1){
    no;
  }
  else{
    yes;
    cout<<dis[lefty][righty]<<endl;
     pathprint(lefty,righty);
  }
  

 
  
 
  
 


 
}



/*
set-deque-pqueue-pair-map-stack-sorting
1)FIND THAT BItCH TEST CASE
2)check complexity
3)Observe properly! Simulate and Draw !
4)Look at /solve the test case , equation
5)Math - Observation -Bf - Greedy -test case pattern
6)Think!Think!Think!Think!Think!Think!Think!Think!Think!
*/





