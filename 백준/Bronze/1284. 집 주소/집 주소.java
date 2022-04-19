import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String n = scan.nextLine();
        while (Integer.parseInt(n) != 0) {
            int sum = 0;
            String[] str = n.split("");
            for (int i = 0; i < str.length; i++) {
                if (str[i].equals("1")) {
                    sum += 2;
                } else if (str[i].equals("0")) {
                    sum += 4;
                } else {
                    sum += 3;
                }
            }
            System.out.println(sum + str.length + 1);
            n = scan.nextLine();
        }
        scan.close();
    }
}
