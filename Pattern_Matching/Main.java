import java.io.*;
import java.util.*;

public class Main {

	public static void solution(String str, String pattern, HashMap<Character,String> map, String op){
        if(str.length() == 0 )
        {
            if(op.length() == 0)
                print(map, pattern);
            return;
        }
        if(op.length() == 0)
            return;
        if(map.containsKey(op.charAt(0))){
            String s = map.get(op.charAt(0));
            int i = 0;
            for(i = 0; i < s.length() && i < str.length(); i++)
            {
                if(s.charAt(i) != str.charAt(i))
                    return;
            }
            if(i == s.length())
                solution(str.substring(i), pattern, map, op.substring(1));
            return;
        }
        String s = "";
        for(int i = 0; i < str.length() ; i++)
        {
            s = s + str.charAt(i);
            map.put(op.charAt(0), s);
            solution(str.substring(i+1), pattern, map, op.substring(1));
            map.remove(op.charAt(0));
        }
	}
	
    private static void print(HashMap<Character, String> map, String pattern) {
        HashSet<Character> set = new HashSet<>();

        for(int i = 0; i < pattern.length() ; i++)
        {
            if(set.contains(pattern.charAt(i)))
            {
                continue;
            }
            System.out.print(pattern.charAt(i)+" -> "+map.get(pattern.charAt(i))+", ");
            set.add(pattern.charAt(i));
        }
        System.out.println(".");
    }

    public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		String pattern = scn.next();
		HashMap<Character,String> map = new HashMap<>();
        solution(str,pattern,map,pattern);
	}
}