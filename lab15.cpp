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
        

//define a temp Movie object and set its data members using the setters
        Movie tempMovie;
            tempMovie.setTitle(tempTitle);
            tempMovie.setYearReleased(tempYear);
            tempMovie.setScreenWriter(tempWriter);
            movieVector.push_back(tempMovie);

            fin.close();
    }else {
        
        cout << "File not found." << endl;
    }
    for (Movie m : movieVector) {
        cout << "Movie: " << m.getTitle() << endl;          
        cout << "    Year released: " << m.getYearReleased() << endl; 
        cout << "    Screenwriter: " << m.getScreenWriter() << endl; 
    }
}
    return 0;
}