class Solution {
public:
    string intToRoman(int num) {
        string conversion;
        while(num > 0){
            if(num >= 1000) conversion += 'M', num -= 1000;
            else if(num >= 900) conversion += "CM", num -= 900;
            else if(num >= 500) conversion += 'D', num -= 500;
            else if(num >= 400) conversion += "CD", num -= 400;
            else if(num >= 100) conversion += 'C', num -= 100;
            else if(num >= 90) conversion += "XC", num -= 90;
            else if(num >= 50) conversion += 'L', num -= 50;
            else if(num >= 40) conversion += "XL", num -= 40;
            else if(num >= 10) conversion += 'X', num -= 10;
            else if(num >= 9) conversion += "IX", num -= 9;
            else if(num >= 5) conversion += 'V', num -= 5;
            else if(num >= 4) conversion += "IV", num -= 4;
            else conversion += 'I', num -= 1;
        }
        cout << num;
        return conversion;
    }
};