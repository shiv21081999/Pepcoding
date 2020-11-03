import java.io.*;
import java.util.*;

public class Main {

    public static void solution(int[] arr, int index, int n , int k,int[] subsetSum, ArrayList<ArrayList<Integer>> ans) {
        if(index == n && k == 0)
        {
            if(isBalances(subsetSum))
            {
                print(ans);
            }
            return;
        }
        if(index >= n)
            return;
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans.get(i).size() == 0)
            {
                ans.get(i).add(arr[index]);
                subsetSum[i]+=arr[index];
                solution(arr, index + 1, n, k-1, subsetSum, ans);
                subsetSum[i]-=arr[index];
                ans.get(i).remove(ans.get(i).size() - 1);
                break;
            }
            else
            {
                ans.get(i).add(arr[index]);
                subsetSum[i]+=arr[index];
                solution(arr, index+1, n, k, subsetSum, ans);
                ans.get(i).remove(ans.get(i).size() - 1);
                subsetSum[i] -= arr[index];
            }
        }
	}

    private static boolean isBalances(int[] subsetSum) {
        for (int i = 1; i < subsetSum.length; i++) {
            if (subsetSum[i] != subsetSum[i - 1])
                return false;
        }
        return true;
    }

    private static void print(ArrayList<ArrayList<Integer>> ans) {
        for (int i = 0; i < ans.size(); i++) {
            System.out.print("[");
            int j = 0;
            for (j = 0; j < ans.get(i).size() - 1; j++) {
                System.out.print(ans.get(i).get(j) + ", ");
            }
            System.out.print(ans.get(i).get(j) + "] ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
            sum += arr[i];
        }
        int k = scn.nextInt();
        // if k is equal to 1, then whole array is your answer
        if (k == 1) {
            System.out.print("[");
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + ", ");
            }
            System.out.println("]");
            return;
        }
        // if there are more subsets than no. of elements in array or sum of all
        // elements is not divisible by k
        if (k > n || sum % k != 0) {
            System.out.println("-1");
            return;
        }
        int[] subsetSum = new int[k];
        Arrays.fill(subsetSum, 0);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            ans.add(new ArrayList<>());
        }
        solution(arr, 0, n, k, subsetSum, ans);
        scn.close();
    }

}