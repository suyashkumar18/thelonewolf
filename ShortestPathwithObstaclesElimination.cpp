class Solution {
public:
    struct field{
        int r;
        int c;
        int left;
    };
    bool isvalid(int x,int y,int n,int m)
    {
        if(x>=0 && x<n && y>=0 && y<m)
            return true;
        return false;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n= grid.size(),m=grid[0].size(),i,j;
        queue<struct field> q;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int dist[n+1][m+1][k+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                for(int l=0;l<=k;l++)
                    dist[i][j][l]=1e6;
            }
        }
        for(i=0;i<=k;i++)
            dist[0][0][i]=0;
        int minn=1e6;
        q.push({0,0,k});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x=p.r;
            int y=p.c;
            int z=p.left;
            for(int p=0;p<4;p++)
            {
                int nx,ny,nz;
                nx=x+dx[p];
                ny=y+dy[p];
                nz=z;
                if(isvalid(nx,ny,n,m))
                {
                    if(grid[nx][ny]==0)
                    {
                        if(nz>=0 && dist[nx][ny][z]>(dist[x][y][z]+1))
                        {
                            dist[nx][ny][nz]=dist[x][y][z]+1;
                            q.push({nx,ny,nz});
                        }
                    }
                    else
                    {
                        nz--;
                        if(nz>=0 && dist[nx][ny][nz]>(dist[x][y][z]+1))
                        {
                            dist[nx][ny][nz]=dist[x][y][z]+1;
                            q.push({nx,ny,nz});
                        }
                    }
                }
            }
        }
        for(i=0;i<=k;i++)
            minn=min(minn,dist[n-1][m-1][i]);
        if(minn==1e6)
            return -1;
        return minn;
    }
};
