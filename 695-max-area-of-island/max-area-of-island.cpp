class Solution {
public:

int recursion(int m,int n,int i,int j,int count,vector<vector<int>>& grid,vector<vector<int>>& judge)
        {
            if(i-1>=0&&i-1<m&&grid[i-1][j]==1&&j>=0&&j<n&&judge[i-1][j]==0)
                {
                    judge[i-1][j]=1;
                    ++count;
                    count=recursion(m,n,i-1,j,count,grid,judge);
                }

            if(i+1>=0&&i+1<m&&grid[i+1][j]==1&&j>=0&&j<n&&judge[i+1][j]==0)
                {
                    judge[i+1][j]=1;
                    ++count;
                    count=recursion(m,n,i+1,j,count,grid,judge);
                }

            if(i>=0&&i<m&&j-1>=0&&j-1<n&&grid[i][j-1]==1&&judge[i][j-1]==0)
                {
                    judge[i][j-1]=1;
                    ++count;
                    count=recursion(m,n,i,j-1,count,grid,judge);
                }

            if(i>=0&&i<m&&j+1>=0&&j+1<n&&grid[i][j+1]==1&&judge[i][j+1]==0)
                {
                    judge[i][j+1]=1;
                    ++count;
                    count=recursion(m,n,i,j+1,count,grid,judge);
                }
            
            return count;
        }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int max_count=0;
        int count=0;

        int m,n;
        m=grid.size();
        n=grid[0].size();

        vector<vector<int>> judge(m, vector<int> (n, 0));
        //vector<vector<int>> search(m, vector<int> (n, 0));

        int i,j;

        for(i=0;i<m;++i)
        for(j=0;j<n;++j)
            if(grid[i][j]==1&&judge[i][j]==0)
                {
                    count=1;
                    judge[i][j]=1;
                   
                    count=recursion(m,n,i,j,count,grid,judge);

                    max_count=std::max(max_count, count);

                }

        return max_count;
        
    }
};