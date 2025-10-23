import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    static int max = 0;
    static int safe_num = 0;
    static int virus_num = 0;
    static Queue<Location> q = new LinkedList<>();

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        List<Location> empty = new ArrayList<>();
        for(int x = 0; x < N; x++){
            st = new StringTokenizer(br.readLine());
            for(int y = 0; y < M; y++){
                map[x][y] = Integer.parseInt(st.nextToken());
                if(map[x][y] == 0){
                    safe_num++;
                    empty.add(new Location(x,y));
                } else if(map[x][y] == 2){
                    virus_num++;
                    q.offer(new Location(x,y));
                }
            }
        }

        // 벽 3개 세우기..
        for(int a = 0; a < empty.size(); a++){
            for(int b = a+1; b < empty.size(); b++){
                for(int c = b+1; c < empty.size(); c++){
                    int[][] map_tmp = new int[N][M];
                    for (int i = 0; i < N; i++) {
                        map_tmp[i] = map[i].clone();  // 한 행씩 복사
                    }

                    map_tmp[empty.get(a).x][empty.get(a).y] = 1;
                    map_tmp[empty.get(b).x][empty.get(b).y] = 1;
                    map_tmp[empty.get(c).x][empty.get(c).y] = 1;

                    int sum = virus(map_tmp);
                    if(max < sum) max = sum;
                }
            }
        }

        System.out.println(max);
    }

    // 큐가 끝날때까지 바이러스 감염 + 갯수 세기
    public static int virus(int[][] map_tmp) {
        int s_num = safe_num - 3; // 벽 갯수 빼고 넘겨주기

        Queue<Location> tmp = new LinkedList<>(q);
        while(!tmp.isEmpty()){
            Location location = tmp.poll();
            for(int dir = 0; dir < 4; dir++){
                int nx = location.x + dx[dir];
                int ny = location.y + dy[dir];

                if(nx >= 0 && ny >= 0 && nx < N && ny < M && map_tmp[nx][ny] == 0){
                    map_tmp[nx][ny] = 2;
                    tmp.offer(new Location(nx,ny));
                    s_num--;
                }
            }
        }

        return s_num;
    }
}

class Location {
    int x, y;
    public Location(int x, int y) {
        this.x = x;
        this.y = y;
    }
}