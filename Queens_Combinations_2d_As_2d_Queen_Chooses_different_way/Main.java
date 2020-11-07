import java.io.*;
import java.util.*;

public class Main {
    public static void print(boolean[][] chess) {
        for (int i = 0; i < chess.length; i++) {
            for (int j = 0; j < chess[i].length; j++) {
                if (chess[i][j])
                    System.out.print("q\t");
                else
                    System.out.print("-\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void queensCombinations(int q, int n, boolean[][] chess, int i, int j) {
        if (i == n) {
            if (q == n)
                print(chess);
            return;
        }
        if (j == n) {
            queensCombinations(q, n, chess, i + 1, 0);
            return;
        }
        chess[i][j] = true;
        queensCombinations(q + 1, n, chess, i, j + 1);
        chess[i][j] = false;
        queensCombinations(q, n, chess, i, j + 1);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] chess = new boolean[n][n];

        queensCombinations(0, n, chess, 0, 0);
    }
}