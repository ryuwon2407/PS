import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 번호 -> 이름 (1-based)
        String[] numToName = new String[N + 1];

        // 이름 -> 번호
        Map<String, Integer> nameToNum = new HashMap<>();

        for (int i = 1; i <= N; i++) {
            String name = br.readLine();
            numToName[i] = name;
            nameToNum.put(name, i);
        }

        for (int i = 0; i < M; i++) {
            String q = br.readLine();

            if (q.charAt(0) >= '0' && q.charAt(0) <= '9') {
                int number = Integer.parseInt(q);
                sb.append(numToName[number]).append("\n");
            }
            else {
                sb.append(nameToNum.get(q)).append("\n");
            }
        }

        System.out.print(sb);
    }
}
