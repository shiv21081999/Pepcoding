import java.io.*;
import java.util.*;

public class Main {

    static String max;
    
    public static String swap(String str, int i , int j)
    {
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(i, str.charAt(j));
        sb.setCharAt(j, str.charAt(i));
        return sb.toString();
    }
	public static void findMaximum(String str, int k) {
        if(k == 0)
        {
            if(Integer.parseInt(str) > Integer.parseInt(max))
                max = str;
            return;
        }
        if(Integer.parseInt(str) > Integer.parseInt(max))
            max = str;
        for(int i = 0; i < str.length()-1; i++)
        {
            for(int j = i + 1; j < str.length() ; j++)
                findMaximum(swap(str, j, i), k-1);
        }
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		int k = scn.nextInt();
		 max = str;
		findMaximum(str, k);
		System.out.println(max);
	}

}