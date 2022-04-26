class Solution {
    public int solution(String s) {
        StringBuilder answer = new StringBuilder();
        int len = s.length();
        char[] charArray = s.toCharArray();
        for(int i = 0; i < len; i++) {
            if(charArray[i] >= 'a' && charArray[i] <= 'z') {
                switch (charArray[i]) {
                    case 'z':
                        answer.append("0");
                        i += 3;
                        break;
                    case 'o':
                        answer.append("1");
                        i += 2;
                        break;
                    case 't':
                        if(charArray[i + 1] == 'w') {
                            answer.append("2");
                            i += 2;
                        }
                        else {
                            answer.append("3");
                            i += 4;
                        }
                        break;
                    case 'f':
                        if(charArray[i + 1] ==  'o') {
                            answer.append("4");
                        }
                        else {
                            answer.append("5");
                        }
                        i += 3;
                        break;
                    case 's':
                        if(charArray[i + 1] == 'i') {
                            answer.append("6");
                            i += 2;
                        }
                        else {
                            answer.append("7");
                            i += 4;
                        }
                        break;
                    case 'e':
                        answer.append("8");
                        i += 4;
                        break;
                    case 'n':
                        answer.append("9");
                        i += 3;
                        break;
                }
            }
            else {
                answer.append(charArray[i]);
            }
        }
        return Integer.parseInt(answer.toString());
    }
}