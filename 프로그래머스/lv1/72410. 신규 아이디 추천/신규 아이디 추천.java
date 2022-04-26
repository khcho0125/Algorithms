class Solution {
    public String solution(String new_id) {
        String answer = new_id;
        int len;
        answer = answer.toLowerCase().replaceAll("[^a-z|0-9|_|.|-]", "").replaceAll("[.]+", ".").replaceAll("^[.]|[.]$", "");
        len = answer.length();
        answer = len == 0 ? "a" : answer;
        answer = len >= 16 ? answer.substring(0, 15).replaceAll("^[.]|[.]$", "") : answer;
        if(len <= 2) {
            len = answer.length();
            StringBuilder sb = new StringBuilder();
            sb.append(answer);
            char last = answer.charAt(len - 1);
            for(int i = len; i < 3; i++) {
                sb.append(last);
            }
            answer = sb.toString();
        }
        return answer;
    }
}