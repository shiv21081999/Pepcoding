import java.io.*;
import java.util.*;

public class Main {

    public static void generateWords(int cs, int ts, int []fmap, String asf) {
        if(cs == ts)
        {
            System.out.println(asf);
            return;
        }
        for(int i = 0; i < 26; i++)
        {
            if(fmap[i] > 0)
            {
                char a = (char)(i+97);
                fmap[i]--;
                generateWords(cs+1, ts, fmap, asf+a);
                fmap[i]++;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int[] map = new int[26];
        for (char ch : str.toCharArray()) {
            map[ch - 'a']++;
        }

        generateWords(0, str.length(), map, "");
    }

}