import java.io.*;
import java.util.*;

public class Main {
	static int N, cnt;
	static int[][] map;
	static boolean[][] visited;
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	static int result = 0;
	static int num_max = 0;
	static Queue<coord> q = new LinkedList<coord>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());

		map = new int[N][N];
		for(int x = 0; x < N; x++) {
			st = new StringTokenizer(br.readLine());
			for(int y = 0; y < N; y++) {
				int temp = Integer.parseInt(st.nextToken());
				map[x][y] = temp;
				if(num_max < temp) num_max = temp;
			}
		}
		
		if(num_max == 1) System.out.println(1);
		else search(1);
	}
	
	public static void bfs(int x, int y, int s) {
		q.offer(new coord(x, y));
		while(!q.isEmpty()) {
			visited[x][y] = true;
			coord t = q.poll();
			for(int dir = 0; dir < 4; dir++) {
				int nx = t.x + dx[dir];
				int ny = t.y + dy[dir];
				
				if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if(map[nx][ny] - s > 0 && !visited[nx][ny]) {
						visited[nx][ny] = true;
						q.offer(new coord(nx,ny));
					}
				}
			}
		}
	}
	
	public static void search(int s) {
		if(num_max == s) {
			System.out.println(result);
			return;
		}
		
		cnt = 0;
		visited = new boolean[N][N];
		for(int x = 0; x < N; x++) {
			for(int y = 0; y < N; y++) {
				if(map[x][y]- s > 0 && !visited[x][y]) {
					bfs(x, y, s);
					cnt++;
				}
			}
		}
		
		if(cnt > result) result = cnt;
		search(s+1);
	}
}

class coord {
	int x;
	int y;
	coord(int x, int y){
		this.x = x;
		this.y = y;
	}
}