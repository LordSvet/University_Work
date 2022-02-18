#include <iostream>
#include <string>
#include <vector>


using namespace std;
/// <summary>
/// Creating base class Medium from which all thee derived classes will inherit. It holds four parameters.
/// Made a constructor with optinoal parameters and a copy constructor + destructor. Made getters and setters 
/// and also a virtual toString() function which will be overriden by the derived classes.
/// </summary>
class Medium {

public:
    string abbreviation;
    string author;
    string title;
    int yearPub;

    Medium(string abbreviation = "JOJO", string author = "Hirohiko Araki", string title = "JoJo's normal travellings", int yearPub = 934) {
        this->abbreviation = abbreviation;
        this->author = author;
        this->title = title;
        this->yearPub = yearPub;
    } //Constructor
    Medium(const Medium& medium) {
        abbreviation = medium.abbreviation;
        author = medium.author;
        title = medium.title;
        yearPub = medium.yearPub;
    }  //Copy Constructor

    ~Medium() {} //Destructor

    string getAbb() {
        return abbreviation;
    }
    string getAuth() {
        return author;
    }
    string getTitle() {
        return title;
    }
    int getYears() {
        return yearPub;
    }
    void setAbb(string word) {
        this->abbreviation = word;
    }
    void setAuth(string word) {
        this->author = word;
    }
    void setTitle(string word) {
        this->title = word;
    }
    void setYears(int number) {
        this->yearPub = number;
    }


    virtual string toString() const {
        return "[" + abbreviation + "] " + author + ": " + title;
    }
};

/// <summary>
/// Class Book inherits Medium and adds a string publisher to it. 
/// I have made a setter and a getter
/// and have overriden the toString() function.
/// </summary>
class Book: public Medium {
    public:
        string publisher;
    
        Book(string abbreviation = "JOJO", string author = "Hirohiko Araki", string title = "JoJo's normal travellings",
            int yearPub = 934, string publisher = "Shonen Fall") :
            Medium(abbreviation, author, title, yearPub), publisher{publisher}
        {
        }

        string getPub() {
            return publisher;
        }
        void setPub(string publisher) {
            this->publisher = publisher;
        }

        virtual string toString() const override {
            return "[" + abbreviation + "] " + author + ": " + title + ". Publisher is " + publisher;
        }
};

/// <summary>
/// Class Article also inherits from Medium and adds three new parameters.
/// All of the getters and setters are in place and the toString() function is 
/// implemented.
/// </summary>
class Article: public Medium {
public:
    string mName;
    int mNumber;
    int mPage;


    Article(string abbreviation = "JOJO", string author = "Hirohiko Araki", string title = "JoJo's normal travellings",
        int yearPub = 934, string mName = "Yearly years magazine", int mNumber = 420, int mPage = 69) :
        Medium(abbreviation, author, title, yearPub), mName{mName}, mNumber{mNumber}, mPage{mPage}
    {
    }


    string getmName() {
        return mName;
    }
    void setmName(string mName) {
        this->mName= mName;
    }   
    int getmNumber() {
        return mNumber;
    }
    void setmNumber(int mNumber) {
        this->mNumber= mNumber;
    }   
    int getmPage() {
        return mPage;
    }
    void setmPage(int mPage) {
        this->mPage = mPage;
    }
    
    virtual string toString() const override {
        return "[" + abbreviation + "] " + author + ": " + title + ". " + mName + ", "
                + to_string(mPage) + ", " + to_string(yearPub) + ", " + to_string(mNumber) + ".";
    }

};

/// <summary>
/// Class Bibliography which is a vector of Medium*.
/// I made three insert methods depending on what kind of medium is inserted(Book, Article or Medium).
/// I made the appropriate operator[] and << overloading.
/// </summary>
class Bibliography{
public:
    int size;
    vector<Medium*> array;
  
    Bibliography(int size = 4) {
        this->size = size;
    };
    ~Bibliography() {
    }

    void insert(Medium* medium) {
        if (array.size() > size) {
            throw("Size exceeded!");
        }
        array.push_back(medium);
    }
    void insert(Book* medium) {
        if (array.size() > size) {
            throw("Size exceeded!");
        }
        array.push_back(medium);

    }
    void insert(Article* medium) {
        if (array.size() > size) {
            throw("Size exceeded!");
        }
        array.push_back(medium);

    }


    Medium* operator[](string abbreviation) const { //Overloading [] operator
    
        for (int i = 0; i < size; i++) {
            if (abbreviation == array[i]->abbreviation) {
                return array[i];
            }
            else if (i == size-1 && abbreviation != array[i]->abbreviation) {
                return nullptr;
            }
        }
    }
    friend ostream& operator<<(ostream& stream, const Bibliography& bb) { //Overloading << operator for printing
        
        for (int i = 0; i < bb.array.size(); i++) {
            stream << bb.array[i]->toString() << endl;
        }  
        return stream;
    }
};



using namespace std;
void testBibliography()
{
    // create bibliography
    Bibliography myBibliography(10);
    Book* b1 = new Book("Ra01",
        "Dietmar Ratz",
        "Grundkurs Programmieren in Java",
        2001,
        "Hanser-Verlag");
    Book* b2 = new Book("Kr03",
        "Guido Krueger",
        "Handbuch der Java-Programmierung",
        2003,
        "Addison-Wesley");
    Article* a1 = new Article("Pa72",
        "D. L. Parnas",
        "On the Criteria To Be Used in Decomposing Systems into"
        ,
        1972,
        "Communications of the ACM",
        15,
        1053);

        myBibliography.insert(b1);
        myBibliography.insert(b2);
        myBibliography.insert(a1);
        cout << "Bibliography:" << endl << myBibliography; //display bibl.
        cout << endl << (*myBibliography["Pa72"]).toString() << endl;
    
    
}
/// <summary>
/// Used the given test class to test the code.
/// </summary>
int main(int argc, char* argv[])
{
    testBibliography();
    cin.sync(); cin.get();
    return 0;
}
