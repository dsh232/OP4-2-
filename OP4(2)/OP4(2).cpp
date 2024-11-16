#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> removeSpacesBetweenQuestions(vector<char> text) {
    int firstQuestionIndex = -1;
    int secondQuestionIndex = -1;
    bool ifContuine = true;
    // Находим индексы первого и второго знаков вопроса.
    for (int i = 0; text.size() > i && ifContuine; ++i) {
        if (text[i] == '?' ) {
            if (firstQuestionIndex == -1) {
                firstQuestionIndex = i;
            }
            else {
                secondQuestionIndex = i;
                ifContuine = false;
            }
        }
    }
    ifContuine = true;
    if (firstQuestionIndex != -1 && secondQuestionIndex != -1) {
        for (int i = firstQuestionIndex + 1; i < secondQuestionIndex && ifContuine; ++i) {
            if (text[i] == '?') {
                ifContuine = false;
            }
            if (text[i] == ' ') {
                text.erase(text.begin() + i);
                i--;
            }
        }
    }
    return text;
}

int main()
{
    vector<char> str;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open())
    {
        char symbol;
        while (inputFile.get(symbol)) {
            str.push_back(symbol);
        }

        str = removeSpacesBetweenQuestions(str);

        ostream_iterator<char> output_iterator(outputFile);  //вывод результата  в файл
        copy(str.begin(), str.end(), output_iterator);

        return 0;
    }
    else
    {
        cout << "file is not found.";
    }
    str.clear();
    inputFile.clear();
    outputFile.clear();
}