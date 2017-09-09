class Solution {
public:
	/*
	* @param n: An integer
	* @return: A list of strings.
	*/
	vector<string> fizzBuzz(int n) {
		// write your code here
		string str;
		vector<string> result;
		for (int i = 1; i <= n; i++) {
			str = "";
			if (i % 3 == 0) {
				str += "fizz";
				if (i % 5 == 0) {
					str += " buzz";
				}
			}
			else if (i % 5 == 0) {
				str += "buzz";
			}
			else {
				str = to_string(i);
			}
			result.push_back(str);
		}
		return result;
	}
};