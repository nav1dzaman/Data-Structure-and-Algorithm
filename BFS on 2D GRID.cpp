lli MX=100;
lli lev[100][100];
lli m,n;
bool vs[100][100];
char st[100][100];
lli dx[]={1,-1,0, 0, 1,1,-1,-1};
lli dy[]={0, 0,1,-1,-1,1,1,-1};

void bfs(int fx,int fy) /// starting position
{
    lli i,v,x,y,md=0;
    queue <pair<lli,lli>> q;
    vs[fx][fy]=1;
   // lev[fx][fy]=0;
    q.push({fx,fy});
    while(!q.empty()){
        auto pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<8;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            if(x<0||x>=n||y<0||y>=m)continue; 
            if(vs[x][y]==0 && st[x][y]=='@'){ 
                q.push({x,y});
                vs[x][y]=1;
            }
        }

    }
    

}
int main()
{
 
}