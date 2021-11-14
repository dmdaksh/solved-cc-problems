#include <iostream>
#define N 5
using namespace std;

bool isSafe(int x, int y, int maze[N][N]){
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y] == 1){
        return true;
    }
    return false;
}

void printSolution(int solution[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << solution[i][j];
        }
        cout << endl;
    }
}

bool solveMaze(int maze[N][N], int x, int y, int solution[N][N]){
    if(x == 4 && y == 4){
        solution[x][y] = 1;
        return true;
    }
    if(isSafe(x, y, maze)){
        solution[x][y] = 1;
        
        if(solveMaze(maze, x+1, y, solution)){
            return true;
        }
        
        if(solveMaze(maze, x, y+1, solution)){
            return true;
        }

        solution[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int maze[N][N] = {{1,1,0,0,0},
                    {0,1,0,0,0},
                    {1,1,1,1,1},
                    {0,0,0,0,1},
                    {0,0,1,1,1}};
    int solution[N][N] = {0};
    if(solveMaze(maze, 0, 0, solution)){
        printSolution(solution);
    }
}