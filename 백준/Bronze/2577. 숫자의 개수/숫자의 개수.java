import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int result = 1;
        int[] array = new int[10];
        for (int i = 0; i < 3; i++) {
            result *= scan.nextInt();
        }
        String[] str = Integer.toString(result).split("");
        for(String a : str) {
            int b = Integer.parseInt(a);
            array[b]++;
        }
        for(int i = 0; i < 10; i++) {
            System.out.println(array[i]);
        }
        scan.close();
    }
}