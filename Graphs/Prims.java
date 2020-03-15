//author @Nishant

import java.util.Scanner;
/**
 *
 * @author NSTG
 */
public class Main {
    
    static Scanner scan = new Scanner(System.in);
    static int mat[][] = new int[100][100];
    static int selected[] = new int[100];
    static int x = 1;
    static int max, minCost = 0;
    static int a, b, c, d;
        
    
    public static void main(String[]args){
        int n;
        selected[1] = 1;
        //System.out.println("Prim's Algorithm for Minimum Spanning Tree\n");
        //System.out.println("Enter number of nodes: ");
        n = scan.nextInt();
                
        //System.out.println("Enter values for matrix: ");
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                //System.out.println(i+":"+j+": ");
                mat[i][j] = scan.nextInt();
                
                if(mat[i][j]==0){
                    mat[i][j]=1111;
                }
                
            }
        }
        
        while(x<n){
            max = 1111;
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    if(mat[i][j]<max){
                        if(selected[i]!=0){
                            max = mat[i][j];
                            
                            a = i;
                            b = j;
                            c = i;
                            d = j;
                        }
                    }
                }
            }
            if(selected[c]==0 || selected[d]==0){
                //System.out.println("("+a+"-->"+b+") Cost: "+max);
                minCost += max;
                selected[b] = 1;
                x++;
            }
            mat[a][b] = mat[b][a] = 555;                                                                                       
        }
        System.out.print("\nMinimun cost="+minCost);        
    }
}
