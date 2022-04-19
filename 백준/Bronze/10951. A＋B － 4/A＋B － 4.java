import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n, m;
        while(scan.hasNext()) {
            n = scan.nextInt();
            m = scan.nextInt();
            System.out.println(n + m);
        }
        scan.close();
    }
}