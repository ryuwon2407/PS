import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();

        for(int t = 0; t < T; t++){
            String temp  = br.readLine();
            LinkedList<Character> list = new LinkedList<>();
            ListIterator<Character> iter = list.listIterator();

            for(int i = 0; i < temp.length(); i++){
                char c = temp.charAt(i);

                if(c == '<'){
                    if(iter.hasPrevious()) iter.previous();  // 커서를 왼쪽으로 이동
                } else if(c == '>') {
                    if(iter.hasNext()) iter.next();          // 커서를 오른쪽으로 이동
                } else if(c == '-') {
                    if(iter.hasPrevious()) {
                        iter.previous();
                        iter.remove();                        // 커서 앞 문자 삭제
                    }
                } else {
                    iter.add(c);                              // 현재 커서 위치에 삽입
                }
            }

            StringBuilder sb = new StringBuilder();
            for(char ch : list) sb.append(ch);
            output.append(sb).append('\n');
        }
        bw.write(output.toString());
        bw.flush();
        bw.close();
    }
}