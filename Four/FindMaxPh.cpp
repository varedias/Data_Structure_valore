#include <iostream>
#include <string>
#include <vector>

void maxcommentstr(std::string &   string1, std::string&  string2, int & maxlen, int & pos1, int & pos2) {
 
    int m = string1.size();
    int n = string2.size();

    //创建一个二维数组
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    maxlen = 0; 
    pos1 = 0;   
    pos2 = 0;   

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (string1[i - 1] == string2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxlen) {
                    maxlen = dp[i][j];
                    pos1 = i - maxlen;
                    pos2 = j - maxlen;
                }
            }
        }
    }
}

int main() {
    std::string string1 = "abcdef";
    std::string string2 = "zabcf";
    int maxlen = 0;
    int pos1 = 0;
    int pos2 = 0;

    maxcommentstr(string1, string2, maxlen, pos1, pos2);

    if (maxlen > 0) {
        std::cout << "maxlength: " << maxlen << std::endl;
        std::cout << "pos1: " << pos1 << std::endl;
        std::cout << "pso2: " << pos2 << std::endl;
        std::cout << "max commment string: " << string1.substr(pos1,maxlen) << std::endl;
    } else {
        std::cout << "no comment string " << std::endl;
    }

    return 0;
}
