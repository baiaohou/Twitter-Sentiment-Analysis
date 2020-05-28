#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class Sentence {

    /* Implement the Sentence class for Part 1 here! */
    
    // field
    private:
    int score;
    
    private:
    string text;
    
    // constructor
    public:
    Sentence() {
        score = 0;
        text = "";
    }
    
    Sentence(int score, string name) {
        this->score = score;
        this->text = name;
    }
    
    // functions
    int getScore() {
        return score;
    }
    
    string getText() {
        return text;
    }

    void setScore(int score) {
        this->score = score;
    }
    
    void setText(string name) {
        this->text = name;
    }
    
    void toLower() {
        boost::to_lower(text);
    }
};