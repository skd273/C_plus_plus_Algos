//function checks if placement of queen at xth row and yth column is safe or not 
//returns true or false based on if any other queen has already been placed in the same row or column or diagonally
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

//place a queen in ith row of 'col' column. Recursively place other queens and verify that placement(isSafe)
//backtrack to a previous placement if that placement is invalid
bool nqueens(vector<string> &board,int n,int col,int &cnt){
	//if n queens are placed in n columns successfully, increment cnt. You got a solution!
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
	
	//chessboard is initially empty '.'(dots) of size nxn
	vector<string> board(n,str);
	int cnt = 0;
	nqueens(board,n,0,cnt);
	//cnt: total possible ways to place n-queens
	cout<<cnt;
}
