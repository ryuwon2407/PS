import java.io.*;
import java.util.*;

public class Main {
    static int N = 0, M = 0;
    static int[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        list = new int[N+1];

        dfs(1, 0);
    }

    public static void dfs(int start, int depth) {
        if (depth == M) {
            for(int m = 0; m < M; m++)
                System.out.print(list[m]+" ");
            System.out.println();
        } else {
            for (int i = start; i <= N; i++){
                list[depth] = i;
                dfs(i+1,depth+1);
            }
        }
    }
}