class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int evenNumbers = n, oddNumbers = n;
        int i = 1;
        int sumOdd = 0, sumEven = 0;
        // find sumodd/even
        while (evenNumbers > 0 && oddNumbers > 0) {
            if (i % 2 == 1 && oddNumbers > 0) {
                sumOdd += i;
                oddNumbers--;
            }

            if (i % 2 == 0 && evenNumbers > 0) {
                sumEven += i;
                evenNumbers--;
            }
            i++;
        }

        return gcd(sumEven, sumOdd);
    }
};