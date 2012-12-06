#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
using std::pair;
using std::cout;
using std::endl;

int main (int argc, char** argv){

  if(argc != 2){
    cout << "Usage: list [tweets!]" << endl;
  }
  else{
    cout << "Input file: " << argv[1] << endl;

    map<string, int> words;
    string word;
    int total = 0;
    ifstream file(argv[1]);
    
    if(file.is_open()){
      while(file.good()){
        getline(file, word, ' ');
        if(word != ""){
          total++;
          if(words.count(word)){
            words[word]++;
          }
          else{
            words.insert(pair<string, int>(word, 1));
          }
        }
      }
    }
    //Order them. <map> sorts by key value so make # of occurences the key
    map<int, string> order;
    map<string, int>::iterator it;
    for(it = words.begin(); it != words.end(); ++it){
      order.insert(pair<int, string>((*it).second, (*it).first));
    }
    
    //put in a file

    ofstream orderFile("orderedWords");
    map<int, string>::iterator it0 = order.begin();
    if(orderFile.is_open()){
      while(orderFile.good()){
        for(double i = 0 ; i != order.size(); ++i){
          orderFile << (*it0).second << "  " << (*it0).first << endl;
          it0++;
        }
        orderFile.close();
      }
    }
    //Analysis. Calculate total words/unique words
    ofstream analysis("analysis");
    if(analysis.is_open()){
      while(analysis.good()){
        analysis << "Total: " << total << endl;
        analysis << "Unique words: " << words.size() << endl;
        analysis << "Lexical Diversity: " << total / words.size() << endl;
        analysis.close();
      }
    }
  }

}
