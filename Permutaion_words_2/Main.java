import java.io.*;
import java.util.*;

public class Main {
  public static void print(Character[] str)
  {
    for(int i = 0; i < str.length; i++)
    {
      System.out.print(str[i]);
    }
    System.out.println();
  }
  public static void generateWords(int cc, String str, Character[] spots, HashMap<Character, Integer> lastOccurence) {
    if (cc == str.length()) {
      print(spots);
      return;
    }
    char a = str.charAt(cc);
    int lo = lastOccurence.get(a);
    for(int i = lo + 1; i < spots.length; i++)
    {
      if(spots[i] == null)
      {
        spots[i] = a;
        lastOccurence.put(a, i);
        generateWords(cc+1, str, spots, lastOccurence);
        spots[i] = null;
        lastOccurence.put(a, lo);
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();

    Character[] spots = new Character[str.length()];
    HashMap<Character, Integer> lastOccurence = new HashMap<>();
    for (char ch : str.toCharArray()) {
      lastOccurence.put(ch, -1);
    }

    generateWords(0, str, spots, lastOccurence);
  }

}