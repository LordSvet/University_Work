#include <iostream>

using namespace std;

///Created class Vector with the attribues dimension, value and a dynamically allocated array dynamic as private. Dynamic is of type double as the values inserted in it are double as well.
///The vector dynamic will be the dynamically allocated data structure we will be using.
///Under public I made a regular constructor with two optional parameters, a destructor and a copy constructor.
///After that are the setters and getters and the overloading of the [], = and << operators.
class Vector{
    private: 
        int dimension;
        double value;
        double* dynamic;    //Dynamically allocated array
    public:
        Vector(int dimension = 2, double value = 0){    //Constructor with two optional parameters
            this->dimension = dimension;
            this->value = value;
            dynamic = new double[dimension];
            for(int i = 0; i < dimension; i++){
                dynamic[i] = value;
            }
        }
        ~Vector(){  //Destructor
            delete[] dynamic;
        }
        
        Vector(const Vector &vectorCopy){      //Copy Constructor
            dimension = vectorCopy.dimension;
            value = vectorCopy.value;
            dynamic = new double[dimension];
            for(int i = 0; i < dimension; i++){
                dynamic[i] = vectorCopy.dynamic[i];
            }
        }

        Vector& operator=(const Vector& copy){  //Overloading assignment operator
            dimension = copy.dimension;
            value = copy.value;
            for(int i = 0; i < dimension; i++){
                dynamic[i] = copy.dynamic[i];
            }
            return *this;
        }

        //Setter and Getters

        int getDimension(){
            return dimension;
        }
        double getValue(int index){
            return dynamic[index];
        }
        void setValue(int index, double value){
            dynamic[index] = value;  
        }

        double operator[](int index) const{ //Overloading [] operator
            if(index >= dimension){
                cout << "Error found. Index " << index << " is out of bounds.";
                exit(0);
            }
            return dynamic[index];
        }

        friend ostream& operator<<(ostream& stream, const Vector &vector) { //Overloading << operator for printing
            stream << "(";

            for(int i = 0; i < vector.dimension; i++){
                if(i == vector.dimension - 1)
                    stream << vector[i];
                else    
                stream << vector[i] << ", ";
            }
            stream << ")" << endl;
            return stream;
    }

        
};


///In the main class I have tested it by creating three Vector objects and setting value and copying/assigning values and making sure the cout << works fine.

int main(){

    Vector v1(4, 5.12);
    v1.setValue(1, 4);
    v1.setValue(2, 12413.123);
    v1.setValue(3, 69.420);

    std::cout << v1 << std::endl;
    std::cout << v1[1] << std::endl;

    Vector v2 = v1;
    std::cout << v2 << std::endl;
    Vector v3 = v1;
    v3.setValue(3, 12.8);
    v2 = v3;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;

    return 0;
}