#include <cmath>
class Solution {
public:
    bool checkPowersOfThree(int n) {

        int num = 0;

        int HighestExponent = cbrt(n);
        if (HighestExponent > 19) HighestExponent = 19;
        while (HighestExponent >= 0) {
            int PowerOfThreeInteger = PowerOfThree(HighestExponent);
            if (num + PowerOfThreeInteger <= n) num += PowerOfThreeInteger;
            HighestExponent--;
        }

        return num == n;

    }

    int PowerOfThree(int Exponantial) {
        int num = 1;
        while (Exponantial > 0)
        {
            num *= 3;
            Exponantial--;
        }
        return num;
    }

};