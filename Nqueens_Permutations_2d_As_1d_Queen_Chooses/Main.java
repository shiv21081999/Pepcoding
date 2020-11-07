import java.io.*;
import java.util.*;

public class Main {

    public static void print(int [][] chess)
    {
        for(int i = 0; i < chess.length ; i++)
        {
            for(int j = 0; j < chess.length; j++)
            {
                System.out.print(chess[i][j] == 0 ? "-\t" : "q"+chess[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static boolean IsQueenSafe(int[][] chess, int row, int col) {
        for (int i = 0; i < chess.length; i++) {
            if (chess[row][i]!=0)
                return false;
            if (chess[i][col]!=0)
                return false;
        }
        int i = row + 1, j = col + 1;
        for (; i < chess.length && j < chess.length; i++, j++) {
            if (chess[i][j]!=0)
                return false;
        }
        i = row - 1;
        j = col - 1;
        for(; i >= 0 && j >= 0; i--, j--)
        {
            if(chess[i][j]!=0)
                return false;
        }
        i = row -1;
        j = col +1;
        
        for(;i >= 0 && j < chess.length; j++, i--)
        {
            if(chess[i][j]!=0)
                return false;
        }
        i = row + 1;
        j = col - 1;
        for(; i < chess.length && j >= 0; i++, j--)
        {
            if(chess[i][j]!=0)
                return false;
        }
        return true;
    }

    public static void nqueens(int qpsf, int tq, int[][] chess) {
        if(qpsf == tq)
        {
            print(chess);
            return;
        }
        for(int i = 0; i < chess.length; i++)
        {
            for(int j = 0;j < chess.length ; j++)
            {
                if(chess[i][j] == 0 && IsQueenSafe(chess, i, j))
                {
                    chess[i][j] = qpsf + 1;
                    nqueens(qpsf+1, tq, chess);
                    chess[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] chess = new int[n][n];

        nqueens(0, n, chess);
    }
}