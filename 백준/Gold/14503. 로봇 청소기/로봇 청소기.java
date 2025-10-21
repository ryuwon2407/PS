import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    
    static int num = 0;

    // 0: 북, 1: 동, 2: 남, 3: 서
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int dir = Integer.parseInt(st.nextToken());
        Location start = new Location(x, y, dir);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        simulate(start);
        System.out.println(num);
    }

    public static void simulate(Location cur) {
        while (true) {
            // 1. 현재 칸 청소
            if (map[cur.x][cur.y] == 0) {
                map[cur.x][cur.y] = 2;
                num++;
            }

            boolean moved = false; // 이번 턴에 이동했는지 체크

            // 2. 4방향 탐색 (왼쪽부터 시작)
            for (int i = 0; i < 4; i++) {
                cur.d = (cur.d + 3) % 4; // 반시계 회전
                int nx = cur.x + dx[cur.d];
                int ny = cur.y + dy[cur.d];

                // 청소되지 않은 빈 칸이면 이동
                if (map[nx][ny] == 0) {
                    cur = new Location(nx, ny, cur.d);
                    moved = true;
                    break; // 바로 이동 후 다시 1단계로
                }
            }

            // 3. 이동하지 못했다면 (4방 다 막힘)
            if (!moved) {
                int backDir = (cur.d + 2) % 4;
                int bx = cur.x + dx[backDir];
                int by = cur.y + dy[backDir];

                // 뒤가 벽이면 종료
                if (map[bx][by] == 1) {
                    break;
                } else {
                    // 후진 (방향 유지)
                    cur = new Location(bx, by, cur.d);
                }
            }
        }
    }
}

class Location {
    int x, y, d;
    public Location(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }
}