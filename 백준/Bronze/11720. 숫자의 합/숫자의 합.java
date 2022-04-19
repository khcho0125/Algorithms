import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += reader.read() - 48;
        }
        System.out.println(result);
        reader.close();
    }
}