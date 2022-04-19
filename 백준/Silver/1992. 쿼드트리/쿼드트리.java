import java.util.Scanner;

public class Main {

    public static String[][] str = new String[64][64];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String s = scan.nextLine();
        for (int i = 0; i < n; i++) {
            str[i] = scan.nextLine().strip().split("");
        }
        System.out.println(func(n, 0, 0));
        scan.close();
    }

    public static String func(int n, int x, int y) {

        if (n == 1) {
            return str[x][y];
        } else {
            String one = func(n / 2, x, y);
            String two = func(n / 2, x, y + n / 2);
            String three = func(n / 2, x + n / 2, y);
            String four = func(n / 2, x + n / 2, y + n / 2);
            if (one.equals(two) && one.equals(three) && one.equals(four) && one.length() == 1) {
                return one;
            } else {
                String s = "(";
                return s.concat(one).concat(two).concat(three).concat(four).concat(")");
            }
        }
    }
}