import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int mul = 1;
            int N = Integer.parseInt(br.readLine());

            HashMap<String, Integer> map = new HashMap<>();
            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                String temp = st.nextToken(); // 앞 값은 필요 없으니 제거
                temp = st.nextToken();

                if(!map.containsKey(temp)){
                    map.put(temp, 1);
                } else {
                    map.put(temp, map.get(temp) + 1);
                }
            }

            if(map.size() == 1){
                System.out.println(map.values().iterator().next());
            } else {
                for(String s : map.keySet()) {
                    mul *= map.get(s) + 1;
                }
                System.out.println(mul - 1);
            }
        }
        br.close();
    }
}