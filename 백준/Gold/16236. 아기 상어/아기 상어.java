import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static Location cur; // 아기 상어의 현재 위치
    static int time = 0; // 총 시간
    static int eatCount = 0; // 현재 사이즈에서 먹은 물고기 수

    static int[] dx = {-1, 0, 0, 1};
    static int[] dy = {0, -1, 1, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];

        for (int x = 0; x < N; x++) {
            st = new StringTokenizer(br.readLine());
            for (int y = 0; y < N; y++) {
                map[x][y] = Integer.parseInt(st.nextToken());
                if (map[x][y] == 9) {
                    map[x][y] = 0; // 상어 있는 곳도 결국 빈 칸으로 처리
                    cur = new Location(x, y, 2);
                }
            }
        }

        // 더 이상 먹을 수 있는 물고기가 없을 때까지 반복
        while (true) {
            Location target = bfs();
            if (target == null) break;

            time += target.dist;

            cur.x = target.x;
            cur.y = target.y;

            map[target.x][target.y] = 0;

            // 먹은 수 증가 및 사이즈 업 체크
            eatCount++;
            if (eatCount == cur.size) {
                cur.size++;
                eatCount = 0;
            }
        }

        System.out.println(time);
    }

    // BFS로 가장 가까운 먹잇감 찾는 함수
    public static Location bfs() {
        visited = new boolean[N][N];
        Queue<Location> q = new ArrayDeque<>();
        q.offer(new Location(cur.x, cur.y, cur.size, 0));
        visited[cur.x][cur.y] = true;

        Location target = null;

        while (!q.isEmpty()) {
            Location temp = q.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nx = temp.x + dx[dir];
                int ny = temp.y + dy[dir];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] > cur.size) continue; // 큰 물고기 있는 칸은 통과 불가

                visited[nx][ny] = true;
                int nextDist = temp.dist + 1;
                
                if (map[nx][ny] > 0 && map[nx][ny] < cur.size) {
                    if (target == null) {
                        target = new Location(nx, ny, cur.size, nextDist);
                    } else {
                        if (nextDist < target.dist ||
                                (nextDist == target.dist && (nx < target.x || (nx == target.x && ny < target.y)))) {
                            target = new Location(nx, ny, cur.size, nextDist);
                        }
                    }
                }
                
                q.offer(new Location(nx, ny, cur.size, nextDist));
            }
        }

        return target;
    }
}

class Location {
    int x;
    int y;
    int size;
    int dist;

    public Location(int x, int y, int size) {
        this.x = x;
        this.y = y;
        this.size = size;
        this.dist = 0;
    }

    public Location(int x, int y, int size, int dist) {
        this.x = x;
        this.y = y;
        this.size = size;
        this.dist = dist;
    }
}
