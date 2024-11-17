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
        if (text[i] == '?') {
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
  
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open())
    {
        char symbol;
        vector<char> arr;
        ostream_iterator<char> output_iterator(outputFile);
        while (inputFile.get(symbol)) {
            if (symbol == '\n') {
                arr = removeSpacesBetweenQuestions(arr);
                arr.push_back('\n');
                copy(arr.begin(), arr.end(), output_iterator);
                arr.erase(arr.begin(), arr.end());    //обнуляем вектор с новой строки
            }
            else arr.push_back(symbol);           
        }

        cout << "succes. ";
          //вывод результата  в файл
        arr = removeSpacesBetweenQuestions(arr);
        copy(arr.begin(), arr.end(), output_iterator);

        return 0;
    }
    else
    {
        cout << "file is not found.";
    }
    inputFile.clear();
    outputFile.clear();
}