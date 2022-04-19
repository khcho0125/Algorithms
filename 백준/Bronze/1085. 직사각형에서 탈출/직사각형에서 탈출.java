import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int[] num = new int[4];
        for (int i = 0; i < num.length; i++) {
            num[i] = scan.nextInt();
        }

        int length = num[2] - num[0];
        int width = num[3] - num[1];
        System.out.println((num[0] < num[1] ? num[0] : num[1]) < (length < width ? length : width)
                ? (num[0] < num[1] ? num[0] : num[1])
                : (length < width ? length : width));
        scan.close();
    }
}