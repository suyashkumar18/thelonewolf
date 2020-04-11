class Solution {
public:
    bool isvalid(int x,int y,int n,int m)
    {
        if(x>=0 && x<n && y>=0 && y<m)
            return true;
        return false;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m= board[0].size(), i, j,k;
        vector<vector<char>> ans;
        queue<pair<int,int> > q;
        int dx[]={1,-1,0,0,1,1,-1,-1};
        int dy[]={0,0,1,-1,1,-1,1,-1};
        q.push({click[0],click[1]});
        bool visited[n+1][m+1];
        memset(visited,false,sizeof(visited));
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        else
        {
            while(!q.empty())
            {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                visited[x][y]=true;
                q.pop();
                int cnt=0;
                for(i=0;i<8;i++)
                {
                    int nx= x+dx[i];
                    int ny= y+dy[i];
                    
                    if(isvalid(nx,ny,n,m))
                    {
                        if(board[nx][ny]=='M')
                        {
                            cnt++;
                        }
                    }
                }
                if(cnt==0)
                {
                    board[x][y]='B';
                    for(i=0;i<8;i++)
                    {
                        int nx= x+dx[i];
                        int ny= y+dy[i];

                        if(isvalid(nx,ny,n,m))
                        {
                            if(board[nx][ny]=='E' && !visited[nx][ny])
                            {
                                visited[nx][ny]=true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
                else
                {
                    board[x][y]=(char)(cnt+'0');
                }
            }
            return board;
        }
    }
};
