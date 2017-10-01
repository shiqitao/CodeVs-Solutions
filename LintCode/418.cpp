class Solution {
public:
	/*
	* @param n: The integer
	* @return: Roman representation
	*/
	string intToRoman(int n) {
		// write your code here
		int base[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string str[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
			"V", "IV", "I" };
		string roman = "";
		int i = 0;
		while (n != 0) {
			if (n >= base[i]) {
				n -= base[i];
				roman += str[i];
			}
			else {
				i++;
			}
		}
		return roman;
	}
};