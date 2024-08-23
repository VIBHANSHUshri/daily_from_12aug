class Solution {
public:
int m , n;
  void dfs(vector<vector<int>>&grid , int i , int j , vector<vector<bool>>&vis)
  {
    if(i < 0|| i >= m || j <0 || j >= n || vis[i][j] || grid[i][j] == 0)
    {
        return;
    }

    vis[i][j] = true;

    dfs(grid , i + 1 , j , vis );
    dfs(grid , i -1 , j , vis );
    dfs(grid , i  , j - 1, vis );
    dfs(grid , i , j + 1 , vis );
  }
   
    int numberofisland(vector<vector<int>>&grid)
    {
      int islands = 0;
      vector<vector<bool>>vis(m,vector<bool>(n));

      for(int i = 0; i < m ; i++)
      {
        for(int j = 0 ; j < n ; j++)
        {
           if(grid[i][j] == 1 && vis[i][j] == 0 ) //Land
           {  
               dfs(grid,i,j,vis);
               islands++; 
           }
        }
      }

      return islands;
    }
    int minDays(vector<vector<int>>& grid) {
      //we follow the simple pattern of dfs for each island 
      m = grid.size();
      n = grid[0].size();

      int islands = numberofisland(grid);


      if(islands > 1 || islands == 0)
      {
        return 0;
      }

      else
      for(int i = 0 ; i < m ; i++)
      {
        for(int j = 0 ; j < n ; j++)
        {
            if(grid[i][j] == 1)
            {
                grid[i][j] = 0;
                islands = numberofisland(grid);
                if(islands > 1 || islands == 0)
                {
                    return 1;
                }

                grid[i][j] = 1;
            }
        }
      }
          return 2; 
    }
};