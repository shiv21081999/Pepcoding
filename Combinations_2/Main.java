import java.io.*;
import java.util.*;

public class Main {

  public static void combinations(int[] boxes, int ci, int ti, int lb){
    if(lb == boxes.length)
    {
      if(ci == ti)
      {
        print(boxes);
      }
      return;
    }
    boxes[lb] = 1;
    combinations(boxes, ci+1, ti, lb+1);
    boxes[lb] = 0;
    combinations(boxes, ci, ti, lb+1);
  }
  public static void print(int []arr)
  {
    for(int i = 0; i < arr.length; i++)
    {
      if(arr[i] == 1)
        System.out.print('i');
      else
        System.out.print('-');
    }
    System.out.println();
  }
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int nboxes = Integer.parseInt(br.readLine());
    int ritems = Integer.parseInt(br.readLine());
    combinations(new int[nboxes], 0, ritems, 0);
  }

}