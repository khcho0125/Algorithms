import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Map<String, Integer> dogam = new HashMap<>();
        int n = scan.nextInt();
        int m = scan.nextInt();
        int i;
        String[] dogamidx = new String[n + 1];
        String str;
        for (i = 0; i <= n; i++) {
            str = scan.nextLine();
            dogam.put(str, i);
            dogamidx[i] = str;
        }

        for (i = 0; i < m; i++) {
            str = scan.nextLine();
            if (str.charAt(0) > 47 && str.charAt(0) < 58) {
                System.out.println(dogamidx[Integer.parseInt(str)]);
            } else {
                System.out.println(dogam.get(str));
            }
        }
    }
}
