import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long result = 0;
        int T = Integer.parseInt(br.readLine());

        // 왼쪽에서 오른쪽으로 보는 시야로 값이 들어올때마다 확인
        Deque<long[]> stack = new ArrayDeque<>();
        for (int i = 0; i < T; i++) {
            long h = Long.parseLong(br.readLine());
            long count = 1; // 자기 자신

            // 현재 사람보다 키가 작은 사람들은 다 pop하면서 쌍을 센다
            while(!stack.isEmpty() && stack.peek()[0] < h){
                result += stack.peek()[1];
                stack.pop();
            }

            // 현재 사람과 키가 같은 사람이 있다면
            if (!stack.isEmpty() && stack.peek()[0] == h) {
                long same = stack.peek()[1];
                result += same; // 같은 키끼리는 서로 다 볼 수 있음
                count += same;  // 블록으로 묶기
                stack.pop();    // 기존 같은 키 블록 제거

                // 만약 스택에 더 남아있을 경우 보이니까
                if (!stack.isEmpty()) {
                    result++;
                }
            }
            // 현재 사람보다 키가 큰 사람이 남아있다면
            else if (!stack.isEmpty()) {
                // 현재 사람은 맨 앞의 큰 사람도 볼 수 있다
                result++;
            }

            // 현재 사람 push (키, count)
            stack.push(new long[]{h, count});
        }

        System.out.println(result);
    }
}

// (1,2) (2,3) (2,4) (2,5) (2,6) (3,4) (3,5) (4,5) (4,6) (6,7)
// 절대 O(N^2)이 되어선 안됨