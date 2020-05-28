#include "Sentence.h"
#include "Word.h"
//#include "Analyzer.cpp"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

// Please do not change the signatures of these functions!
vector<Sentence*>* readFile(char*);
map<string, double>* wordScores(vector<Sentence*>&);
double calculateSentenceScore(map<string, double>&, string);

int main(int argc, char* argv[]) {

  /* IMPLEMENT THIS FUNCTION ACCORDING TO THE SPECIFICATION FOR EACH PART */
   
 
    
    char* filename = argv[1];
    vector<Sentence*>* sent_vec = readFile(filename);
    if (sent_vec == NULL) return -1;
//     cout << (*sent_vec).size() << endl;
    
    
    map<string, double>* sent_map = wordScores(*sent_vec);
    
    
    string line;
    while (line.compare("quit") != 0) {
        cout << "Type your sentence here:" << endl;
        getline(cin, line);
        
        double score = calculateSentenceScore(*sent_map, line);
        if (line.compare("quit") == 0) break;
        cout << "SCORE IS " << score << endl << endl;
    }
    cout << "bye-bye! :)" << endl;
    
    // free malloced space
    for (int i = 0; i < (*sent_vec).size(); i++) {
        delete (*sent_vec)[i];
    }
    delete sent_vec;

    delete sent_map;
    return 0;

}
