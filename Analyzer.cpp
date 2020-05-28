#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <stdio.h>
#include "Sentence.h"
#include "Word.h"

#include <boost/algorithm/string.hpp>
#include <string>
using namespace boost;
using namespace std;

/*
 * Implement the three functions below according to the specification.
 */


/*
 * This function should read the specified file and return a vector
 * containing pointers to a Sentence object for each well-formatted line.
 */
vector<Sentence*>* readFile(char* filename) {

      /* IMPLEMENT THIS FUNCTION IN PART 1 */
    string line;
    ifstream myfile(filename);
    
    vector<Sentence*>* ret = new vector<Sentence*>();
    
    if (myfile.is_open()) {
        
        int count = 0;
        
        while (getline(myfile, line)) {
            //cout << line << endl;
            
            int score = -99;
            string name = "";
            
            if (line[0] == '-' && line[2] == ' ' && line[3] != 0) {
                if (line[1] == '1') {
                    // number is -1
                    score = -1;
                } else if (line[1] == '2') {
                    // number is -2
                    score = -2;
                }
                name = line.substr(3);
            } else if (line[1] == ' ' && line[2] != 0) {
                if (line[0] == '0') {
                    // number is 0
                    score = 0;
                } else if (line[0] == '1') {
                    // number is 1
                    score = 1;
                } else if (line[0] == '2') {
                    // number is 2
                    score = 2;
                }
                name = line.substr(2);
            }
            
            if (score != -99) {
                //cout << "[" + name + "]" << endl;
                //to_lower(name);
                Sentence* s = new Sentence(score, name);
                ret->push_back(s);
                count++;
            }
        }
        
//         cout << count << endl;
//         cout << (*ret).size() << endl;
        
        myfile.close();
    } else {
        delete ret;
        if (filename == NULL) {
            cout << "[ERROR] You did not enter your filename!\n";
        } else {
            cout << "[ERROR] Can't open " << filename << " for read\n";
        }
        return NULL;
    }
    
  return ret; // change this as needed!

}

/*
 * This function takes the vector of Sentence pointers and calculates the
 * average score for each word. The return value maps the word to its score.
 */
map<string, double>* wordScores(vector<Sentence*>& sentences) {
    
    /* IMPLEMENT THIS FUNCTION IN PART 2 */
//     cout << "abc\n";
    //int size = (sentences).size();
//     cout << size << endl;
    
    // whole word map
    map<string, Word*> word_map;
    

    for (int i = 0; i < sentences.size(); i++) {
//         cout << "\n\n[NEW LINE]" << endl;
        
        Sentence* sen = sentences[i];
        
//         cout << (*sen).getText() << endl;
        (*sen).toLower();
//         cout << (*sen).getText() << endl;

        vector<string> fields;
        string tempStr = (*sen).getText();
        split(fields, tempStr, is_any_of(" ")); // split(fields, s, is_any_of(" "));
        for (size_t n = 0; n < fields.size(); n++) {

            if (!isalpha(fields[n][0])) { // not alpha
                continue;
            } 

            if (word_map.count(fields[n]) > 0) {
                // word_map has this word. Update
//                 cout << "\n update!!!!" << endl;
                Word *w = word_map[fields[n]];
                (*w).update((*sen).getScore()); // (*w).update(score);
//                 (*w).print();
            } else {
                // this word appears first time
                // add
                Word *w = new Word(fields[n], (*sen).getScore());
//                 (*w).print();
                word_map[fields[n]] = w;
            }

//             cout << "\"" << fields[ n ] << "\"\n";
        }
    }
    
    
//     Sentence* sen = new Sentence(2,  "2 I like caKe 3and  ... ? - coUld8- -Eat cake All DAY . i like eat");
    
    
//     cout << (*sen).getText() << endl;
//     (*sen).toLower();
//     cout << (*sen).getText() << endl;

//     vector<string> fields;
//     string tempStr = (*sen).getText();
//     split(fields, tempStr, is_any_of(" ")); // split(fields, s, is_any_of(" "));
//     for (size_t n = 0; n < fields.size(); n++) {
        
//         if (!isalpha(fields[n][0])) { // not alpha
//             continue;
//         } 
        
//         if (word_map.count(fields[n]) > 0) {
//             // word_map has this word. Update
//             cout << "\n update!!!!" << endl;
//             Word *w = word_map[fields[n]];
//             (*w).update((*sen).getScore()); // (*w).update(score);
//         } else {
//             // this word appears first time
//             // add
//             Word *w = new Word(fields[n], (*sen).getScore());
//             (*w).print();
//             word_map[fields[n]] = w;
//         }
        
//         cout << "\"" << fields[ n ] << "\"\n";
//     }

    map<string, double>* ret = new map<string, double>();
    
    map<string, Word*>::iterator it = word_map.begin();
    while (it != word_map.end()) {
        (*ret)[it->first] = (*(it->second)).getWeight();
        delete it->second;/////<---------------------
        it++;
    }
    
//     cout << "hohohohohoho----\n\n\n";
    
    
    
        map<string, double>::iterator itt = (*ret).begin();
    while (itt != (*ret).end()) {
//         cout << itt->first << " ::: ";
//         cout << itt->second << endl;
        itt++;
    }
    
//     cout << "hi" << endl;
//     // free word_map
//     map<string, Word*>::iterator abc = word_map.begin();
//     cout << "yay" << endl;
//     while (abc != word_map.end()) {
//         cout << "yay" << endl;
//         delete (abc->second);
//         cout << "ho" << endl;
//         it++;
//     }
    
//     cout << "hi" << endl;
    return ret; // change this as needed!

}




/*
 * This function takes the map of words to scores and a string representing
 * a new sentence. The return value is the average of the scores of the
 * words in the sentence.
 */
double calculateSentenceScore(map<string, double>& scores, string sentence) {

    /* IMPLEMENT THIS FUNCTION IN PART 3 */
    to_lower(sentence);
    
    vector<string> fields;
    split(fields, sentence, is_any_of(" "));
    double sum = 0;
    int count = 0;
    for (size_t n = 0; n < fields.size(); n++) {

        if (!isalpha(fields[n][0])) { // not alpha
            continue;
        } 

        if (scores.count(fields[n]) > 0) {
            // word_map has this word, update sum
            sum += (double) scores[fields[n]];
            count++;
        } else {
            // this word appears first time, score = 0
            count++;
        }
        
//         cout << "\"" << fields[ n ] << "\"\n";
    }
    
    if (count == 0) return 0;
    
    double ret = (double) sum / (double) count;    
        
    
    
    return ret; // change this as needed!

}

