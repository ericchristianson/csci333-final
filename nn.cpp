#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

using std::string;
using std::ifstream;
using std::map;
using std::pair;
using std::cout;
using std::endl;

int main(int argc, char** argv){
  if (argc != 3){
    cout << "Usage: list [filename] [threshold]" << endl;
  }
  else{
    cout << "filename: " << argv[1] << endl;
    cout << "threshold: " << argv[2] << endl;

    map<string, int> list;
    string line;

    ifstream file(argv[1]);
    if (file.is_open()){
      while(file.good()){
        getline(file, line);
        if(list.count(line)){
          list[line]++;
        }
        else{
          list.insert(pair<string, int>(line, 1));
        }
      }

      map<string, int>::iterator it;

      cout << "NICE: " << endl;
      cout << endl;
      for(it = list.begin(); it!= list.end(); ++it){
        if ((*it).second >= atoi(argv[2])){
          cout << (*it).first << endl;
        }
      }
      cout << endl; cout << endl;
      cout << "NAUGHTY: " << endl;
      for(it = list.begin(); it != list.end(); ++it){
        if((*it).second < atoi(argv[2])){
          cout << (*it).first << endl;
        }
      }
    }
  }

  return 0;

}
