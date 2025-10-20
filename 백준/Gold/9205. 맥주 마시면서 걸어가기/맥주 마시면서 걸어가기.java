import java.io.*;
import java.util.*;

public class Main {
    static Coordinate home;
    static Coordinate dest;
    static Coordinate[] conv;
    static boolean[] visited;
    static int beers = 20; // 생명줄..

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            // 편의점 갯수
            int N = Integer.parseInt(br.readLine());
            conv = new Coordinate[N];
            visited = new boolean[N];

            // 출발지 좌표
            st =  new StringTokenizer(br.readLine());
            home = new Coordinate(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            // 편의점들 좌표
            for(int n = 0; n < N; n++){
                st = new StringTokenizer(br.readLine());
                conv[n] = new Coordinate(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }

            // 도착지 좌표
            st =  new StringTokenizer(br.readLine());
            dest = new Coordinate(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            if (bfs()) {
                System.out.println("happy");
            } else {
                System.out.println("sad");
            }
        }
    }

    public static boolean bfs() {
        Queue<Coordinate> q = new LinkedList<>();
        q.offer(home);

        while(!q.isEmpty()){
            Coordinate now = q.poll();

            // 현재 위치에서 락페까지 1000m 이하라면 도착 가능
            if(distance(now, dest) <= 1000) return true;

            // 락페까지 한번에 못갈경우 맥주 보충하러 편의점 방문
            for(int i = 0; i < conv.length; i++){
                if(!visited[i] && distance(now, conv[i]) <= 1000) {
                    visited[i] = true;
                    q.offer(conv[i]);
                }
            }
        }
        return false;
    }

    static int distance(Coordinate a, Coordinate b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }
}


class Coordinate {
    int x, y;
    Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

// 취객이 되어보자

// 상근이네 집에서 송도 락페까지 걸어간다
// 50미터가 되기전에 맥주를 한병씩 먹어줘야한다.. 술꾼
// 맥주 한 박스에는 맥주가 20개

// 일단 기본적으로 맥주 한 박스가 있으니 1000m까지는 편의점을 들리지 않아도 그냥 갈듯
// 만약 1000m 이상일 경우 편의점을 들려야하는 것으로 판단
//
