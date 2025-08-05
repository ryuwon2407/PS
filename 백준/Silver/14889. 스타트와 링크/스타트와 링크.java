import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static int[][] map;
	static boolean[] visited; // 팀 구분
	static int min;

	public static void divTeam(int idx, int cnt) {
		if(cnt == N / 2) {
			diff();
			return;
		}for (int i = idx; i < N; i++) {
			if(!visited[i]) {
				visited[i] = true;
				divTeam(i + 1, cnt + 1);
				visited[i] = false;
			}
		}
	}

	public static void diff(){
		int sumA = 0, sumB = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] && visited[j]) {
					sumA += map[i][j];
				} else if (!visited[i] && !visited[j]) {
					sumB += map[i][j];
				}
			}
		}

		int diff = Math.abs(sumA - sumB);
		min = Math.min(min, diff);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());

		map = new int[N][N];
		visited = new boolean[N];
		min = 100000;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		divTeam(0, 0);
		System.out.println(min);
	}
}