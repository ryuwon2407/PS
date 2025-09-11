import java.util.*;
import java.io.*;

public class Main {
    static int n, m, tr1, tr2;
    static boolean[] visit;
    static int[][] graph;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        visit = new boolean[n + 1];
        graph = new int[n + 1][n + 1];
        st = new StringTokenizer(br.readLine());

        tr1 = Integer.parseInt(st.nextToken());
        tr2 = Integer.parseInt(st.nextToken());

        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        System.out.println(bfs(tr1, tr2));
    }

    public static int bfs(int start, int end){
        // end 포인트에 달성 시 cnt return
        // 큐 안에 주변 노드를 계속 넣으면 확인 절차 실시
        // 만약 끝까지 모두 탐색 하였는데 마지막 노드에 달성할 경우 -1
        // level 계산
        int cnt = 0;
        Queue<Integer>q = new LinkedList<>();
        q.offer(start);
        visit[start] = true;

        while(!q.isEmpty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int now = q.poll();
                if (now == end) {
                    return cnt;
                }
                for (int j = 1; j <= n; j++) {
                    if (graph[now][j] == 1 && !visit[j]) {
                        q.offer(j);
                        visit[j] = true;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
}