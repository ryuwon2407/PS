import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        Deque<Integer> stack = new ArrayDeque<Integer>();
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            if(str.equals("push")){
                stack.push(Integer.parseInt(st.nextToken()));
            } else if(str.equals("pop")){
                try {
                    System.out.println(stack.pop());
                } catch (Exception e) {
                    System.out.println("-1");
                }
            } else if(str.equals("size")){
                System.out.println(stack.size());
            } else if(str.equals("empty")){
                System.out.println(stack.isEmpty() ? 1 : 0);
            } else if(str.equals("top")){
                System.out.println(stack.peek() != null ? stack.peek() : -1);
            }
        }

    }
}
