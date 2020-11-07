import java.io.*;
import java.util.*;

public class Main {

    public static void queensPermutations(int index, int n, int row, int col, String asf, boolean[] queens) {
        if (row == n) {
            if (index == n) {
                System.out.println(asf);
                System.out.println();
            }
            return;
        }
        if (col == n) {
            queensPermutations(index, n, row + 1, 0, asf, queens);
            return;
        }
        for (int i = 0; i < queens.length; i++) {
            if (!queens[i]) {
                if (col != n-1) {
                    queens[i] = true;
                    queensPermutations(index + 1, n, row, col + 1, asf + "q" + (i+1) + "\t", queens);
                    queens[i] = false;
                } else {
                    queens[i] = true;
                    queensPermutations(index + 1, n, row, col + 1, asf + "q" + (i+1) + "\n", queens);
                    queens[i] = false;
                }
            }
        }
        if (col == n-1)
            queensPermutations(index, n, row, col + 1, asf + "-\n", queens);
        else
            queensPermutations(index, n, row, col + 1, asf + "-\t", queens);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] queens = new boolean[n];

        queensPermutations(0, n, 0, 0, "", queens);
    }
}