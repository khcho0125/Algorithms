import java.util.Scanner;

public class Main {

    public void Print(String[] str) {
        for (int i = 0; i < 3; i++) {
            System.out.print(str[2 - i]);
        }
    }

    public static void main(String[] args) {

        Main main = new Main();
        Scanner scan = new Scanner(System.in);
        String[] str = scan.next().split("");
        String[] str2 = scan.next().split("");
        int n, m;

        for (int i = 0; i < 3; i++) {
            n = Integer.parseInt(str[2 - i]);
            m = Integer.parseInt(str2[2 - i]);

            if (n == m) {
                continue;
            } else if (n > m) {
                main.Print(str);
                break;
            } else {
                main.Print(str2);
                break;
            }
        }

        scan.close();
    }
}