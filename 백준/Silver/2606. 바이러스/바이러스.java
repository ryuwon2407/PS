import java.io.*;
import java.util.*;

public class Main {

    static int N, E;
    static ArrayList<Integer>[] arr;
    static boolean[] visited;

    static int dfs(int node) {
        if(visited[node]) {
            return 0;
        }
        visited[node] = true;

        int count = 1;
        for(int i : arr[node]) {
            if(!visited[i]) {
                count += dfs(i);
            }
        }
        return count;
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        E = Integer.parseInt(br.readLine());
        
        arr = new ArrayList[N+1];
        visited = new boolean[N+1];
        for (int i = 1; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }

        for(int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            int u =  Integer.parseInt(st.nextToken());
            int v =  Integer.parseInt(st.nextToken());

            arr[u].add(v);
            arr[v].add(u);
        }

        System.out.println(dfs(1) - 1);
        br.close();
    }
}