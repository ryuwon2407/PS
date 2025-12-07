import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[][] map;
    static boolean[][] visited;

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int pictureCount = 0;   // 그림 개수
        int maxArea = 0;        // 가장 큰 넓이

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 1 && !visited[i][j]) {
                    pictureCount++;
                    int area = bfs(i, j);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }

        System.out.println(pictureCount);
        System.out.println(maxArea);
    }

    // BFS로 해당 그림(연결된 1 덩어리)의 넓이를 계산
    static int bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;

        int area = 1;

        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];

            for(int d = 0; d < 4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(visited[nx][ny]) continue;
                if(map[nx][ny] == 0) continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny});
                area++;
            }
        }
        return area;
    }
}