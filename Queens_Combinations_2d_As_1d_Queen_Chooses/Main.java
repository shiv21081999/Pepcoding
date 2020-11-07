import java.io.*;
import java.util.*;

public class Main {

    public static void print(boolean [][]chess)
    {
        for(int i = 0; i < chess.length; i++)
        {
            for(int j = 0; j < chess[i].length; j++)
            {
                if(chess[i][j])
                    System.out.print("q\t");
                else
                    System.out.print("-\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void queensCombinations(int q, int n, boolean[][] chess, int cell) {
        if(cell == n*n)
        {
            if(q == n)
            {
                print(chess);
            }
            return;
        }
        chess[cell/n][cell%n] = true;
        queensCombinations(q+1, n, chess, cell+1);
        chess[cell/n][cell%n] = false;
        queensCombinations(q, n, chess, cell+1);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] chess = new boolean[n][n];

        queensCombinations(0, n, chess, 0);
    }
}