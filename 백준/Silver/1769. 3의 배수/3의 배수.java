import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String[] N = scan.nextLine().split("");
        int j, X = 0, turn = 0;
        for (j = 0, X = 0; j < N.length; j++) {
            X += Integer.parseInt(N[N.length - j - 1]);
        }
        while (N.length > 1) {
            N = String.valueOf(X).split("");
            turn++;
            for (j = 0, X = 0; j < N.length; j++) {
                X += Integer.parseInt(N[N.length - j - 1]);
            }
        }
        if (X % 3 == 0) {
            System.out.println(turn + "\nYES");
        }
        else System.out.println(turn + "\nNO");
        scan.close();
    }
}