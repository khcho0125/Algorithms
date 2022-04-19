import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {

    private static StringBuilder sb = new StringBuilder();

    public static void Success(ArrayDeque<Integer> qDeque, boolean direction) {
        sb.append("[");
        if (qDeque.size() > 0) {
            if (direction) {
                sb.append(qDeque.pollFirst());
                while (!qDeque.isEmpty()) {
                    sb.append(",").append(qDeque.pollFirst());
                }
            } else {
                sb.append(qDeque.pollLast());
                while (!qDeque.isEmpty()) {
                    sb.append(",").append(qDeque.pollLast());
                }
            }
        }
        sb.append("]");
    }

    public static void RemoveDeque(ArrayDeque<Integer> qDeque, String command) {
        boolean direction = true;

        for (char s : command.toCharArray()) {
            if (s == 'R') {
                direction = !direction;
            } else {
                if (direction) {
                    if (qDeque.pollFirst() == null) {
                        sb.append("error");
                        return;
                    }
                } else {
                    if (qDeque.pollLast() == null) {
                        sb.append("error");
                        return;
                    }
                }
            }
        }

        Success(qDeque, direction);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < n; i++) {
            String command = scan.nextLine();
            int size = scan.nextInt();
            scan.nextLine();
            ArrayDeque<Integer> qDeque = new ArrayDeque<>();
            String str = scan.nextLine();
            String[] array = str.substring(1, str.length() - 1).split(",");
            for (int j = 0; j < size; j++) {
                qDeque.add(Integer.parseInt(array[j]));
            }
            RemoveDeque(qDeque, command);
            System.out.println(sb);
            sb.setLength(0);
        }
        scan.close();
    }
}