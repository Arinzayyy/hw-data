#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VectorInt;

void print_vector(VectorInt& vec)
{
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}

void permutations(VectorInt & vec, int j, int s)
{
    if(j == s)
    {
        print_vector(vec);
        return;
    }

    for(int i = j ; i<= s; ++i)
    {
        std::swap(vec[j], vec[i]);
        permutations(vec, j+1 ,s);
        std::swap(vec[j], vec[i]);
    }
}

int main()
{
    int UserInput;
    cout << "Please Enter a number between 1 and 25" << std::endl;
    cin >> UserInput;

    if(UserInput > 25 || UserInput < 1)
    {
        cout << "Number is not between  1 and 25" << std::endl;
        return 0;
    }

    VectorInt vec;
    unsigned long order = 1;
    for(int i = 1; i <= UserInput; ++i)
    {
        vec.push_back(i);
        order *= i;
    }

    cout << "There are " << order << " permutation of the set {";

    for(int i = 0; i < vec.size()-1; ++i)
        cout << vec[i] << ",";
    cout << vec[vec.size() - 1] << "}:" << endl;

    permutations(vec, 0, UserInput-1);

    return 0;
}