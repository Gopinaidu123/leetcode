class Solution {
    public int fib(int n) {
        if ( n == 0 ) {
            return 0 ;
        }
        else if ( n == 1 ) {
            return 1;
        }

        int FirstTerm = 0;
        int SecondTerm = 1;
        for ( int i = 0 ; i<n ; i++) {
            int ThirdTerm = FirstTerm + SecondTerm;

            FirstTerm = SecondTerm;
            SecondTerm = ThirdTerm;
        }
        return FirstTerm;
        
    }
}