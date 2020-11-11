import java.io.*;
import java.util.*;

public class Main {
  
  public static void generateSelection(int it, String ustr, int ssf, int ts, String asf) {
    if(ts == ssf)
    {
      System.out.println(asf);
      return;
    }
    if(it == ustr.length())
      return;
    generateSelection(it+1, ustr, ssf+1, ts, asf+ustr.charAt(it));
    generateSelection(it+1, ustr, ssf, ts, asf);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    int k = Integer.parseInt(br.readLine());

    HashSet<Character> unique = new HashSet<>();
    String ustr = "";
    for (char ch : str.toCharArray()) {
      if (unique.contains(ch) == false) {
        unique.add(ch);
        ustr += ch;
      }
    }

    generateSelection(0, ustr, 0, k, "");
  }

}