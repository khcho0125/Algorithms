import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set<String> set = new HashSet<>(); 
        int N = scanner.nextInt();
        int result = 0;
        scanner.nextLine();
        for(int i = 0; i < N; i++) {
            String str = scanner.nextLine();
            if(str.equals("ENTER")) {
                result += set.size();
                set.clear();
            }
            else {
                set.add(str);
            }
        }
        result += set.size();
        System.out.println(result);
        scanner.close();
    }
}
