/**
 *
 * @author NSTG
 */
import java.util.*;
        
public class Main {
    
    static int count;
    static int[] board;
    
    public static void main(String[]args){
        Scanner scan = new Scanner(System.in);
        
        int N;    
        
        //System.out.println("Enter value of N: ");
        N = scan.nextInt();
      if(N<=3){
        System.out.print("Not possible");
      }
        System.out.println();
        board = new int[N+1];
        
        NQueens(1, N);
    }
    static void NQueens(int row, int N){
        for(int i = 1; i <=N; ++i){
            if(PlaceOrNot(row, i)){
                board[row] = i;
                if(row == N){
                    printBoard(N);
                }else{
                    NQueens(row+1, N);
                }
            }
        }
    }
    
    static boolean PlaceOrNot(int k, int col){
        for(int i = 1; i <= k-1; i++){
            if(board[i] == col){
                return false;
            }else if(Math.abs(board[i]-col) == Math.abs(i-k)){
                return false;
            }
        }
        return true;
    }
    static void printBoard(int n){
        int i,j;
        count++;
      	
        System.out.print("\nSolution "+count+":\n\n");
 		System.out.print("\t");
      for(i=1; i<=n; i++){
          	
        	System.out.print(i+"\t");
        }
      System.out.println();
        for(i=1;i<=n;++i){
            System.out.print("\n"+i);
                for(j=1;j<=n;++j){ //for nxn board
                  //System.out.print(j);
                    if(board[i]==j)
                        System.out.print("\tQ"); //queen at i,j position
                    else
                        System.out.print("\t-"); //empty slot
                }
                System.out.println();
        }
    }
}
