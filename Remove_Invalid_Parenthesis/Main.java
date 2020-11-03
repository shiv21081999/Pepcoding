import java.io.*;
import java.util.*;

public class Main {

	public static void solution(String str, int minRemoval, HashSet<String> ans) {
        if(minRemoval == 0)
        {
            if(isValid(str))
            {
                if(ans.contains(str))
                    return;
                ans.add(str);
                System.out.println(str);
            }
            return;
        }
        for(int i = 0; i < str.length(); i++)
        {
            solution(str.substring(0, i) + str.substring(i+1), minRemoval-1, ans);
        }
	}

	public static int getMin(String str){
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < str.length() ; i++)
        {
            if(str.charAt(i) == '(')
            {
                stack.push('(');
            }
            else{
                if(stack.empty())
                    stack.push(')');
                else if(stack.peek() == '(')
                    stack.pop();
                else if(stack.peek() == ')')
                    stack.push(')');
            }
        }
        return stack.size();
    }
    public static boolean isValid(String str)
    {
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < str.length(); i++)
        {
            if(str.charAt(i) == '(')
            {
                stack.push('(');
            }
            else if(stack.empty())
                return false;
            else
                stack.pop();
        }
        if(stack.empty())
            return true;
        return false;
    }
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
        solution(str, getMin(str),new HashSet<>());
	}
		
}