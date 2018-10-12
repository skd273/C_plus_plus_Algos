bool isSafe(vector<string> board,int x,int y,int n){
        int col = y-1;
        while(col>=0){
            if(board[x][col] == 'Q')
                return false;
            col--;
        }
        int row = x-1;
        col = y-1;
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')
                return false;
            row--;col--;
        }
        row = x + 1;
        col = y - 1;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')
                return false;
            row++;col--;
        }
        return true;
    }
    bool nqueens(vector<string> &board,int n,int col,int &cnt){
        if(col == n){
            cnt++;
            return true;
        }
        bool res = false;
        for(int i = 0;i<n;i++){
            if(isSafe(board,i,col,n)){
                board[i][col] = 'Q';
                if(nqueens(board,n,col+1,cnt))
                    res = true;
                board[i][col] = '.';
            }
        }
        return res;
    }
    
    int main() {
		int n;	//chessboard dim (number of queens)
		cin>>n;
        string str;
        for(int i=0;i<n;++i)
            str+='.';
        vector<string> board(n,str);
        int cnt = 0;
        nqueens(board,n,0,cnt);
        cout<<cnt;
    }
