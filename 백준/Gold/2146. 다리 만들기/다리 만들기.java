import java.util.*;
import java.io.*;
  
public class Main {
	static int[][] map, // 맵 
				   con; // 대륙
	static boolean[][] visited;
	static Queue<Location> loc = new ArrayDeque<>(); // 빠른 시작
	static int N, 
			   min = Integer.MAX_VALUE;
	
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        con = new int[N][N];
        
        for(int i=0; i < N; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0; j < N; j++) 
        		map[i][j] = Integer.parseInt(st.nextToken());
        }
        
        // 대륙 서칭
        int count = 1; // 대륙 개수
    	visited = new boolean[N][N];
    	for(int i=0; i < N; i++) {
        	for(int j=0; j < N; j++) {
        		if(map[i][j] == 0 || visited[i][j]) continue;
        		Queue<Location> temp = new ArrayDeque<Location>();
        		temp.offer(new Location(i, j));
        		visited[i][j] = true;
        		con[i][j] = count;
        		while(!temp.isEmpty()) {
    				Location t = temp.poll();
    				
    				for(int dir=0; dir < 4; dir++) {
    					int nx = t.x + dx[dir];
    	        		int ny = t.y + dy[dir];
    	        		
    	        		if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
    	        		if(map[nx][ny] == 1 && !visited[nx][ny]) {
    	        			temp.offer(new Location(nx, ny));
    	        			visited[nx][ny] = true;
    	        			con[nx][ny] = count;
    	        		}
    				}
        		}
        		loc.offer(new Location(i, j)); // 대륙별 빠른 시작 추가
        		count++;
        	}
        }
    	
    	// 대룩 이어주기
    	for(int i=0; i < N; i++) {
			for(int j=0; j < N; j++) {
				visited = new boolean[N][N]; // visited 초기화
				if(map[i][j] == 0 || visited[i][j]) continue;
				
				int cnt = bfs(i, j);
				if(min > cnt) min = cnt;
			}
		}
    	
    	System.out.println(min);
    }
    
    public static int bfs(int x, int y) {
        Queue<Location> temp = new ArrayDeque<Location>();
        temp.offer(new Location(x, y));
        visited[x][y] = true;

        int cnt = 0; // 바다를 지나가는 거리
        int min_temp = Integer.MAX_VALUE;

        // 바다에서 다른 섬으로 가는 다리 길이 계산을 위해
        // 레벨별로 진행할 수 있도록 size로 한 번에 큐의 각 레벨을 처리
        while (!temp.isEmpty()) {
            int size = temp.size();
            for (int i = 0; i < size; i++) {
                Location t = temp.poll();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = t.x + dx[dir];
                    int ny = t.y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (visited[nx][ny]) continue;

                    if (map[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        temp.offer(new Location(nx, ny));
                    } 
                    else if (map[nx][ny] == 1 && con[x][y] != con[nx][ny]) {
                        min_temp = Math.min(min_temp, cnt);
                    }
                }
            }
            cnt++;
        }
        return min_temp;
    }



}

class Location{
	int x, y;
	Location(int x, int y){
		this.x = x;
		this.y = y;
	}
}