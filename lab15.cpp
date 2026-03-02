// COMSC-210 | Lab  15| Tianyi Cao
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Movie {

private:
//private data members
    string title;
    int yearReleased;
    string screenWriter;

public:
   void setTitle(string t)         { title = t; }
    void setYearReleased(int y)     { yearReleased = y; }
    void setScreenWriter(string s)  { screenWriter = s; }

    string getTitle()               { return title; }
    int getYearReleased()           { return yearReleased; }
    string getScreenWriter()        { return screenWriter; }

};

int main() {
    vector<Movie> movieVector;

    ifstream fin;
    fin.open("input.txt");

    if (fin.good()) {
        string tempTitle, tempWriter;
        int tempYear;

        while (fin){
         if (!getline(fin, tempTitle)) {
             break;
         }
        fin >> tempYear;
        fin.ignore();
        getline(fin, tempWriter);
        fin.close();
    }else {
        
        cout << "File not found." << endl;
    }

}
    return 0;
}