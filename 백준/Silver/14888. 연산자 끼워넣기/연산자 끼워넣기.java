import java.io.*;
import java.util.*;

// 연산자 => 덧셈, 뺄셈, 곱셈, 나눗셈
public class Main {
    static int N;
    static int min = Integer.MAX_VALUE;
    static int max = Integer.MIN_VALUE;
    static int[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        list = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) 
            list[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int plus = Integer.parseInt(st.nextToken()); // 덧셈
        int minus = Integer.parseInt(st.nextToken());// 뺄셈
        int mul = Integer.parseInt(st.nextToken());  // 곱셈
        int div = Integer.parseInt(st.nextToken());  // 나눗셈

        dfs(1, list[0], plus, minus, mul, div);
        System.out.println(max);
        System.out.println(min);
    }

    static void dfs(int idx, int sum, int plus, int minus, int mul, int div){
        if(idx == N){
            max = Math.max(max, sum);
            min = Math.min(min, sum);
            return;
        }
        if (plus > 0) dfs(idx+1, sum + list[idx], plus-1, minus, mul, div);
        if (minus > 0) dfs(idx+1, sum - list[idx], plus, minus-1, mul, div);
        if (mul > 0) dfs(idx+1, sum * list[idx], plus, minus, mul-1, div);
        if (div > 0) dfs(idx+1, sum / list[idx], plus, minus, mul, div-1);
    }
}