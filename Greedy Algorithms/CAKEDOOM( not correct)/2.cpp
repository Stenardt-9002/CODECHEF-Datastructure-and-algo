// #include <iostream>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
//
//
//
// int conver_i(char c)
// {
//   int i = c - '0';
//   return i;
// }
//
// char conver_s(int c)
// {
//   char i = c+48;
//   return i;
// }
//
//
// int main(int argc, char const *argv[])
// {
//   string str1;
//   char c;
//   int x;
//   int i;
//
// x = 0;
// std::cout << x << '\n';
// c = conver_s(x);
// std::cout << c << '\n';
//
//   cin>>str1;
//   // std::cout << str1.size() << '\n';
//
//   for ( i = 0; i < str1.size(); i++)
//   {
//
//       // std::cout << atoi(str1[i]) << '\n';
//       c = str1[i];
//       x = str1[i];
//       // std::cout <<conver_i(str1[i]) << '\n';
//       std::cerr << conver_s() << '\n';
//
//
//   }
//
//   return 0;
// }



#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int k;
		string s;
		cin >> k >> s;
		int n = s.length();

		string ans = "NO";
		for (char c = '0'; c < '0' + k; ++c) {
			string w = s;
			if (w[0] != '?' && w[0] != c) {
				continue;
			}

			bool good = true;
			w[0] = c;
			for (int i = 1; i < n; ++i) {
				bool ok = false;
				for (char d = '0'; d < '0' + k; ++ d) {
					if (w[i] != '?' && w[i] != d) {
						continue;
					}
					if (d != w[i - 1] && d != w[(i + 1) % n]) {
						w[i] = d;
						ok = true;
						break;
					}
				}
				if (!ok) {
					good = false;
					break;
				}
			}
			if (good) {
				ans = w;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
