import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int num = 0;
    static int[][] map;
    static boolean[][] visited;

    static Queue<Location> q = new ArrayDeque<>();

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] > 0) q.offer(new Location(i, j));
                else if (map[i][j] == 0) num++;
            }
        }
        int result = bfs();
        if(num != 0)
            System.out.println(-1);
        else
            System.out.println(result - 1);
    }

    static int bfs() {
        int time = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Location t = q.poll();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = t.x + dx[dir];
                    int ny = t.y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && map[ny][nx] == 0) {
                        q.offer(new Location(ny,nx));
                        visited[ny][nx] = true;
                        num--;
                    }
                }
            }
            time++;
        }

        return time;
    }
}

class Location{
    int x, y;
    Location(int y, int x){
        this.y = y;
        this.x = x;
    }
}