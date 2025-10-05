import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static int[][] map;
	static boolean[][] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int max = 0;

		// 빙하 지도 초기화 및 입력
		map = new int[N][M];
		visited = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
				if (max < map[i][j]) {
					max = map[i][j];
				}
			}
		}

		for(int time = 0; ; time++){
			// 빙하가 몇덩어리인지 검사하는 로직
			int count = 0;
			visited = new boolean[N][M];
			for(int i =0; i < N; i++){
				for(int j =0; j < M; j++){
					if(map[i][j] != 0 && !visited[i][j]){
						count++;
						Queue<int[]> q = new LinkedList<>();
						q.add(new int[] {i, j});
						visited[i][j] = true;

						while(!q.isEmpty()){
							int[] cur = q.poll();
							for(int k =0; k < 4; k++){
								int nx = cur[0] + dx[k];
								int ny = cur[1] + dy[k];
								if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
								if(map[nx][ny] != 0 && !visited[nx][ny]){
									visited[nx][ny] = true;
									q.add(new int[] {nx, ny});
								}
							}
						}
					}
				}
			}
			if(count >= 2){
				System.out.println(time);
				return;
			}
			if(count == 0){
				System.out.println(0);
				return;
			}

			// 빙하 녹이기
			map = melt(N, M);
		}
	}

	// 빙하가 녹이는 로직
	public static int[][] melt(int N, int M){
		int[][] newMap = new int[N][M];
		for(int i =0; i < N; i++){
			for(int j = 0; j < M; j++){
				newMap[i][j] = map[i][j];
			}
		}

		for(int i =0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] != 0){
					int sea = 0;
					for(int k = 0; k < 4; k++){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
						if(map[nx][ny] == 0){ sea++; }
					}
					newMap[i][j] -= sea;
					if(newMap[i][j] < 0){ newMap[i][j] = 0; }
				}
			}
		}
		return newMap;
	}
}