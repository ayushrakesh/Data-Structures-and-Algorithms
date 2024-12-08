#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

long countCombinations(vector<int> &v, int &n, int i, int s)
{ // numbers contains a set of integers
    if (i == n)
    {
        if (s == i)
            return 0;
        return 1;
    }
    long x = 0;
    for (int j = 0; j < s; j++)
    {
        x += countCombinations(v, n, i + 1, s);
    }
    x += countCombinations(v, n, i + 1, s + 1);
    return x;
}

int main()
{
    string inputNumbers;
    getline(cin, inputNumbers);

    vector<int> numbers;
    stringstream ss(inputNumbers);
    int num;

    while (ss >> num)
    {
        numbers.push_back(num);
    }
    int n = numbers.size();
    long result = countCombinations(numbers, n, 0, 0);
    cout << result << endl;

    return 0;
}