#include <fstream>
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

using namespace std;

class Word {
    // field
    private:
    string word;
    double weight;
    int count;
    int sum;
//     double weight;
    
    public:
    Word() {
        count = 0;
        sum = 0;
        weight = 0;
        word = "";
    }
    
    Word(string word, int num) {
        this->count = 1;
        this->sum = num;
        this->weight = sum / count;
        this->word = word;
    }
    
    double update(int num) {
        count++;
        sum += num;
        weight = (double) sum / (double) count;
//         cout << "sum and count: ";
//         cout << sum << "---";
//         cout << count << endl;
//         cout << "weight: " << weight << endl;
        return weight;
    }
    
    double getWeight() {
        return weight;
    }
    
    string getString() {
        return word;
    }
    
    void print() {
        cout << "[" + word + "]: ";
        cout << weight << endl;
    }
};

