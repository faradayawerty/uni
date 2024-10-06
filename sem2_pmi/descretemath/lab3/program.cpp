#include <iostream>

using namespace std;

bool assign_if_not_greater(int val, int thr, int &var);
int binomial(int n, int k);

void print_sets(int n, int k, string s);
int get_number(string word);
string get_word(int num, int n, int k);

int main()
{
	int n, k, num; string word;

	cout << "слово, задающее подмножество: "; cin >> word;
	cout << "его номер: " << get_number(word) << endl;

	cout << "количество элементов в множестве, n = "; cin >> n;
	cout << "количество элементов в подмножестве, k = "; cin >> k;
	cout << "номер подмножества: "; cin >> num;

	cout << "слово, которое ему соответствует: ";
	cout << get_word(num, n, k) << endl;

	cout << "все слова, задающие " << k
		<< "-элементные подмножества, в лексикографическом порядке:\n";
	print_sets(n, k, "");

	return 0;
}

string get_word(int num, int n, int k)
{
	string word(n, '0');
	int line = 0, t;

	for(int i = 0; i < k; i++) {
		line = 0;
		while(assign_if_not_greater(binomial(line, k - i), num, t))
			line++;
		word[word.length() - line] = '1';
		num -= t;
	}

	return word;
}

int get_number(string word)
{
	int num = 0, k = 1;
	for(int i = 1; i <= word.length(); i++) {
		if(word[word.length() - i] == '0')
			continue;
		num += binomial(i - 1, k++);
	}
	return num;
}

void print_sets(int n, int k, string s)
{
	if(n == 0)
		cout << s << endl;
	else {
		if(n > k)
			print_sets(n - 1, k, s + "0");
		if(k > 0)
			print_sets(n - 1, k - 1, s + "1");
	}
}

int binomial(int n, int k)
{
	if(k < 0 || n < 0 || k > n)
		return 0;
	if(k == 0 || n == k)
		return 1;
	return binomial(n-1, k-1) + binomial(n-1, k);
}

bool assign_if_not_greater(int val, int thr, int &var)
{
	bool b = (val <= thr);
	if(b)
		var = val;
	return b;
}

