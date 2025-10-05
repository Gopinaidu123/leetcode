 

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack empty → invalid
                if (stack.isEmpty()) return false;

                char top = stack.pop();

                // Check for matching pairs
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Valid only if no unmatched brackets remain
        return stack.isEmpty();
    }
}
