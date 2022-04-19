import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        HashMap<String, String> cache = new HashMap<>();
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);
        for (int i = 0; i < N; i++) {
            str = br.readLine().split(" ");
            cache.put(str[0], str[1]);
        }
        for (int i = 0; i < M; i++) {
            String input = br.readLine();
            bw.write(cache.get(input) + "\n");
        }
        bw.flush();
    }
}