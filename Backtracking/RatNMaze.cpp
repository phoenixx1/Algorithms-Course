//author @Nishant

#include<bits/stdc++.h>
using namespace std;

void showPath(int **sol, int N) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << " " << sol[i][j] << " ";
      cout << endl;
   }
}

bool isValidPlace(int **mat, int N, int x, int y) {      //function to check place is inside the maze and have value 1
   if(x >= 0 && x < N && y >= 0 && y < N && mat[x][y] == 1)
      return true;
   return false;
}

bool solveRatMaze(int **sol, int **mat, int N, int x, int y) {
   if(x == N-1 && y == N-1) {       //when (x,y) is the bottom right room
      sol[x][y] = 1;
      return true;
   }

   if(isValidPlace(mat, N, x, y) == true) {     //check whether (x,y) is valid or not
      sol[x][y] = 1; //set 1, when it is valid place
      if (solveRatMaze(sol, mat, N, x+1, y) == true)       //find path by moving right direction
         return true;
      if (solveRatMaze(sol, mat, N, x, y+1) == true)         //when x direction is blocked, go for bottom direction
         return true;
      sol[x][y] = 0;         //if both are closed, there is no path
      return false;
   }  
   return false;
}

bool findSolution(int **sol, int **mat, int N) {
   if(solveRatMaze(sol, mat, N, 0, 0) == false) {
      cout << "There is no path";
      return false;
   }
   cout << "\nPath to get out of maze" << endl;
   showPath(sol, N);
   return true;
}

int main() {
    int N;
    cout << "Enter n value:";
    cin >> N;
    int **mat = (int **)malloc(N * sizeof(int *));
    for(int i=0; i<N; i++){
        mat[i] = (int *)malloc(N * sizeof(int));
    }
    int **sol = (int **)malloc(N * sizeof(int *));
    for(int i=0; i<N; i++){
        sol[i] = (int *)malloc(N * sizeof(int));
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mat[i][j];
        }
    }
    findSolution(sol, mat, N);
}