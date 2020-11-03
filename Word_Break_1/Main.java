import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		HashSet<String> dict = new HashSet<>();
		for(int i = 0  ; i  < n; i++){
			dict.add(scn.next());
		}
		String sentence = scn.next();
		wordBreak(sentence,"", dict);
	}

	public static void wordBreak(String str, String ans, HashSet<String> dict){
        if(str.length() == 0)
        {
            System.out.println(ans);
        }
        String s = "";
        for(int i = 0; i < str.length() ; i++)
        {
            s = s+str.charAt(i);
            if(dict.contains(s))
            {
                wordBreak(str.substring(i+1), ans+s+" ", dict);
            }
        }
	}
		
}