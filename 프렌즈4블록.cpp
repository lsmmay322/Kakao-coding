#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool compBlock(vector <string> board, int i, int j) {
    if (toupper(board[i][j]) == toupper(board[i + 1][j]))
        if (toupper(board[i][j]) == toupper(board[i][j + 1]))
            if (toupper(board[i][j]) == toupper(board[i + 1][j + 1]))
                return true;
    return false;
}

int changeBlock(vector<string>* board, int i, int j, int answer)
{
    int n;
    if (isupper((*board)[i][j]))
    {
        (*board)[i][j] += 32;
        answer++;
    }
    if (isupper((*board)[i + 1][j])) {
        (*board)[i + 1][j] += 32;
        answer++;
    }
    if (isupper((*board)[i][j + 1]))
    {
        (*board)[i][j + 1] += 32;
        answer++;
    }
    if (isupper((*board)[i + 1][j + 1]))
    {
        (*board)[i + 1][j + 1] += 32;
        answer++;
    }

    return answer;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool finish = false;
    bool isChange = false;
    int l;

    while (!finish)
    {
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++) {
                cout << i << ' ' << j << '\n';
                if (board[i][j] != ' ' && compBlock(board, i, j))
                {
                    answer = changeBlock(&board, i, j, answer);
                    isChange = true;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            cout << board[i] << endl;
            if (i == board.size() - 1) {
                for (int j = 0; j < n; j++) cout << '-';
                cout << '\n';
            }
        }
        if (!isChange)
            finish = true;
        bool check = false;
        if (isChange) {
            for (int i = 0; i < n; i++)
            {
                for (int j = m - 2; j >= 0; j--)
                {
                    for (int k = j; k < m - 1; k++)
                    {
                        if (board[k + 1][i] == ' ' || islower(board[k + 1][i]))
                        {
                            board[k + 1][i] = board[k][i];
                            board[k][i] = ' ';
                        }

                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            cout << board[i] << endl;
            if (i == board.size() - 1) {
                for (int j = 0; j < n; j++) cout << '-';
                cout << '\n';
            }
        }
        isChange = false;
    }

    return answer;
}

int main(void)
{
    string arr[] = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    //string arr2[] = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    //string arr3[] = { "AAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAA" };
    //string arr4[] = { "AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA" };
    vector <string> testCase(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    //vector <string> testCase2(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
    //vector <string> testCase3(arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0])));
    //vector <string> testCase4(arr4, arr4 + (sizeof(arr4) / sizeof(arr4[0])));

    cout << "사라지는 블럭 수 : " << solution(4, 5, testCase) << "\n" << endl;
    //cout << "사라지는 블럭 수 : " << solution(6, 6, testCase2) << "\n" << endl;
    //cout << "사라지는 블럭 수 : " << solution(5, 15, testCase3) << "\n" << endl;
    //cout << "사라지는 블럭 수 : " << solution(5, 6, testCase4) << "\n" << endl;

    return 0;
}
