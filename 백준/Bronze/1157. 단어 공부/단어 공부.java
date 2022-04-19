import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String[] str = scan.nextLine().toUpperCase().replace(" ", "").split("");
        int[] array = new int[26];
        char result = '?';
        int j = 0;
        for (String s : str) {
            array[s.charAt(0) - 65] += 1;
        }
        for (int i = 0; i < array.length; i++) {
            if (j < array[i]) {
                result = (char) (i + 65);
                j = array[i];
            } else if (j == array[i]) {
                result = '?';
            }
        }
        System.out.println(result);
        scan.close();
    }
}