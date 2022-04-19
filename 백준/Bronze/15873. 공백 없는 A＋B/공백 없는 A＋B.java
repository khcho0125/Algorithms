import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        int result = 0;
        String[] str = scan.nextLine().split("");
        for (String s : str) {
            if (s.equals("0")) {
                result += 9;
            }
            result += Integer.parseInt(s);
        }
        System.out.println(result);
    }
}