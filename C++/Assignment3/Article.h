#include <iostream>
using namespace std;

///Creating class Article which holds the attributes numberOfArticel, description, costPrice and orderDuration
class Article{
public:
///numberOfArticel holds the No from the original stock file
    int numberOfArticel;
///description holds the Desciprtion from the original stock file
    string description;
///costPrice holds the Cost Price from the original stock file
    double costPrice;
///orderDuration holds the Order Duration from the original stock file
    int orderDuration;
};
///Creating class Stock which holds the attributes articleNumber, actualStock, maximumStock and consumption
///
class Stock{
public:
///articleNumber holds the No from the original stock file
    int articleNumber;
///actualStock holds the Actual Stock from the original stock file    
    int actualStock;
///maximumStock holds the Maximum Stock from the original stock file
    int maximumStock;
///consumption holds the Consumption per Day from the original stock file
    int consumption;
};
