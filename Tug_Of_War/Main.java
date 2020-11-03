import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int[] arr = new int[scn.nextInt()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        solve(arr, 0, new ArrayList<>(), new ArrayList<>(), 0, 0);
        System.out.println(ans);
    }

    static int mindiff = Integer.MAX_VALUE;
    static String ans = "";

    public static void solve(int[] arr, int vidx, ArrayList<Integer> set1, ArrayList<Integer> set2, int soset1,
            int soset2) {
        if (vidx == arr.length) {
            if ((int) Math.abs(set1.size() - set2.size()) <= 1) {
                int diff = (int) Math.abs(soset1 - soset2);
                if (diff < mindiff) {
                    mindiff = diff;
                    ans = getAns(set1, set2);
                }
            }
            return;
        }
        set1.add(arr[vidx]);
        solve(arr, vidx + 1, set1, set2, soset1 + arr[vidx], soset2);
        set1.remove(set1.size() - 1);
        set2.add(arr[vidx]);
        solve(arr, vidx + 1, set1, set2, soset1, soset2 + arr[vidx]);
        set2.remove(set2.size() - 1);

    }

    private static String getAns(ArrayList<Integer> set1, ArrayList<Integer> set2) {
        String ans = "[";
        for (int i = 0; i < set1.size() - 1; i++) {
            ans = ans + set1.get(i) + ", ";
        }
        ans = ans + set1.get(set1.size() - 1) + "] [";
        for (int i = 0; i < set2.size() - 1; i++) {
            ans = ans + set2.get(i) + ", ";
        }
        ans = ans + set2.get(set2.size() - 1) + "]";
        return ans;
    }

}