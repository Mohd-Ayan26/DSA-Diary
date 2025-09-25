class Solution {
private:
    bool safe(vector<vector<char>>& board,int val,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==val)
            {
                return false;
            }
            if(board[row][i]==val)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            {
                return false;
            }
        }
       return true;
    }
    bool solve(vector<vector<char>>& board,int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char val='1';val<='9';val++)
                    {
                        if(safe(board,val,i,j))
                        {
                        board[i][j]=val;
                        //recursive call
                        bool check=solve(board,n);
                        if(check)
                        {
                            return true;
                        }
                        else
                        {
                            //backtracing
                            board[i][j]='.';
                        }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,board.size());

    }
};
