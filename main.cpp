#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned minIndex = index;
    
    for (unsigned i = index; i < vals.size(); ++i) {
        if (vals.at(i) < vals.at(minIndex)) {
            minIndex = i;
        }
    }
    
    return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned i = 0; i < vals.size(); ++i) {
        swap(vals.at(i), vals.at(min_index(vals, i)));
    }
}

char getChar(vector<char> vals, int index) {
    try {
        return vals.at(index);
    }
    catch (out_of_range& excpt) {
        cout << "out of range exception occured" << endl;
        exit(0);
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for (int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){ 

     //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar = 'a';
    int index;
    int numOfRuns = 5;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        curChar = getChar(vals,index);
        cout << curChar << endl;
    }
     
    return 0;
}