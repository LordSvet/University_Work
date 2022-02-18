#include <iostream>

using namespace std;

class Medium{

    private:
        string abbreviation;
        string author;
        string title;
        int yearsPub;
    public:
        Medium(string abbreviation, string author, string title, int yearsPub){ //Constructor
            this->abbreviation = abbreviation;
            this->author = author;
            this->title = title;
            this->yearsPub = yearsPub;
        }

        string getAbb(){
            return abbreviation;
        }
         string getAuth(){
            return author;
        }
        string getTitle(){
            return title;
        }
        int getYears(){
            return yearsPub;
        }
        void setAbb(string word){
            this->abbreviation = word;
        }
        void setAuth(string word){
            this->author = word;
        }
        void setTitle(string word){
            this->title = word;
        }
        void setYears(int number){
            this->yearsPub = number;
        }


};

int main(){


    cout << "as";
    return 0;
}
