import java.util.*;
import java.io.*;
 
public class Solution {
    static int N, M;
    static List<List<Integer>> adj;
    static List<List<Integer>> radj;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        StringTokenizer st;
 
        int T = Integer.parseInt(br.readLine()); 
 
        for (int tc = 1; tc <= T; tc++) {
            N = Integer.parseInt(br.readLine().trim());
            M = Integer.parseInt(br.readLine().trim());
 
            adj = new ArrayList<>(N + 1);
            radj = new ArrayList<>(N + 1);
            for (int i = 0; i <= N; i++) {
                adj.add(new ArrayList<>());
                radj.add(new ArrayList<>());
            }
 
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                adj.get(a).add(b);
                radj.get(b).add(a);
            }
 
            int knownRankCount = 0;
            for (int i = 1; i <= N; i++) {
                int higher = bfsCount(i, adj);   // i보다 큰 학생 수
                int lower  = bfsCount(i, radj);  // i보다 작은 학생 수
 
                if (higher + lower == N - 1) {
                    knownRankCount++;
                }
            }
            out.append('#').append(tc).append(' ').append(knownRankCount).append('\n');
        }
 
        System.out.print(out);
    }
 
    static int bfsCount(int start, List<List<Integer>> graph) {
        boolean[] visited = new boolean[N + 1];
        Queue<Integer> q = new ArrayDeque<>();
        visited[start] = true;
        q.offer(start);
 
        int reach = 0; // start를 제외한 도달한 정점 수
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : graph.get(cur)) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    reach++;
                    q.offer(nxt);
                }
            }
        }
        return reach;
    }
}