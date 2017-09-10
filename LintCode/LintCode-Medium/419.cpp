class Solution {
public:
	/*
	* @param s: Roman representation
	* @return: an integer
	*/
	int romanToInt(string &s) {
		// write your code here
		int base[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string str[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
			"V", "IV", "I" };
		int n = 0;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < 13; j++) {
				if (j % 2 == 0 && s[i] == str[j][0]) {
					n += base[j];
					break;
				}
				if (j % 2 == 1 && s[i] == str[j][0] && s[i + 1] == str[j][1]) {
					n += base[j];
					i++;
					break;
				}
			}
		}
		return n;
	}
};