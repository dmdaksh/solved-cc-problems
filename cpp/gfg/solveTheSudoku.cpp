#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findUnoccupiedCell(int **sudoku, int &row, int &col){
    for(row = 0; row < N; row++){
        for(col = 0; col < N; col++){
            if(sudoku[row][col] == 0) return true;
        }
    }
    return false;
}

bool inRow(int **sudoku, int row, int num){
    for(int c = 0; c < N; c++) if(sudoku[row][c] == num) return true;
    return false;
}

bool inCol(int **sudoku, int col, int num){
    for(int r = 0; r < N; r++) if(sudoku[r][col] == num) return true;
    return false;
}

bool inMat(int **sudoku, int row, int col, int num){
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            if(sudoku[r+row][c+col] == num) return true;
        }
    }
    return false;
}

bool numNotThere(int **sudoku, int row, int col, int num){
    return !inRow(sudoku, row, num) && !inCol(sudoku, col, num) && !inMat(sudoku, row-row%3, col-col%3, num) && sudoku[row][col] == 0;
}

bool solve(int **sudoku){
    int row = 0, col = 0;
    if(!findUnoccupiedCell(sudoku, row, col)) return true;
    
    for(int num = 1; num <= N; num++){
        if(numNotThere(sudoku, row, col, num)){
            sudoku[row][col] = num;
            if(solve(sudoku)) return true;
            sudoku[row][col] = 0;
        }
    }    
    return false;
}

void printSudoku(int **sudoku){
    cout << endl;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++) cout << sudoku[r][c] << " ";
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int **sudoku = new int*[N];
	    for(int i = 0; i < N; i++){
            sudoku[i] = new int[N];
	        for(int j = 0; j < N; j++){
	            cin >> sudoku[i][j];
	        }
	    }
	    if(solve(sudoku)) printSudoku(sudoku);
	}
}

// int main(){
//     int matrix[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
//                       {5, 2, 0, 0, 0, 0, 0, 0, 0},  
//                       {0, 8, 7, 0, 0, 0, 0, 3, 1},  
//                       {0, 0, 3, 0, 1, 0, 0, 8, 0},  
//                       {9, 0, 0, 8, 6, 3, 0, 0, 5},  
//                       {0, 5, 0, 0, 9, 0, 6, 0, 0},  
//                       {1, 3, 0, 0, 0, 0, 2, 5, 0},  
//                       {0, 0, 0, 0, 0, 0, 0, 7, 4},  
//                       {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
//     if(solve(matrix)) printSudoku(matrix);
//     else cout << "No Solution" << endl;
// }