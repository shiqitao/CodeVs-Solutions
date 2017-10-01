class Solution {
public:
	/*
	* @param str: A string
	* @return: a boolean
	*/
	bool isUnique(string &str) {
		// write your code here
		int size = str.size();
		int repeat[128];
		memset(repeat, 0, sizeof(int)* 128);
		for (int i = 0; i < size; i++) {
			if (repeat[str[i]]) {
				return false;
			}
			else {
				repeat[str[i]]++;
			}
		}
		return true;
	}
};