class Solution {
public:
	/**
	* @param chars: The letters array you should sort.
	*/
	void sortLetters(string &letters) {
		// write your code here
		int size = letters.size();
		for (int i = 0, j = size - 1; i < j;) {
			while (i < j && letters[i] <= 'z' && letters[i] >= 'a') {
				i++;
			}
			while (i < j && letters[j] <= 'Z' && letters[j] >= 'A') {
				j--;
			}
			int temp = letters[i];
			letters[i] = letters[j];
			letters[j] = temp;
		}
	}
};