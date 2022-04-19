import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int i = 0, result = 1, pre = 0; i < T; i++, result = 1, pre = 0) {
            HashMap<String, Integer> clothes = new HashMap<>();
            int N = scan.nextInt();
            scan.nextLine();
            int[] jungsu = new int[N];
            for (int j = 0; j < N; j++) {
                String str = scan.nextLine().split(" ")[1];
                if (!clothes.containsKey(str)) {
                    clothes.put(str, pre++);
                }
                jungsu[clothes.get(str)]++;
            }
            for (int j = 0; j < pre; j++) {
                result *= jungsu[j] + 1;
            }
            System.out.println(result - 1);
        }
        scan.close();
    }
}