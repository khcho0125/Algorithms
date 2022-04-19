import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        String n;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            n = scan.next();
            if (n.equals("W")) {
                cnt++;
            }
        }
        if (cnt == 0) {
            System.out.println(-1);
        } else if (cnt < 3) {
            System.out.println(3);
        } else if (cnt < 5) {
            System.out.println(2);
        } else {
            System.out.println(1);
        }
        scan.close();
    }
}