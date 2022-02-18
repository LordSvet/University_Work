#include "Article.h"
#include <iostream>
#include <fstream>
using namespace std;

///First I create the two objects article and stock of type Article and type Stock accordingly. I use totalStockValue, reorderPoint and orderProposal to save later calculations in the loop.
///Using the ifstream and ofstream functinons from <fstream> I open the files which will be read and/or written.
///I first write the column titles in reorder. Then create col to hold column characters from the stock file, descHelper for the second column as there are two strings inside
///and line where the whole line of the stock file will be saved in the while loop.
///The while loop goes through every single line, saves it in line and I copy all of the read values into the article and stock objects.
///Inside the loop I calculate the total stock value and also write the new table with Reorder Point and Order Proposal into Reorder.txt.
///At the end I just print the total stock value and then close both of the files.
int main(){

    Article article;
    Stock stock;
    
    double totalStockValue{};
    int reorderPoint{};
    int orderProposal{};

    ifstream database("Assignment3.txt"); //Opens file for reading
    ofstream reorder("Reorder.txt"); //Opens file for writing

    reorder << " Reorder Point\t" << "| " << "Order Proposal" << endl;
    
    string col; //saves the column in the original file so it can be skipped
    string descHelper; //second part of description words as they are two
    string line; //string where the read line will be saved

        while(getline(database, line)){ 
            if(database >> article.numberOfArticel >> col >> descHelper >> article.description >> col >> stock.actualStock >> col >> stock.maximumStock >> col >> article.costPrice >> col >> col >> stock.consumption >> col >> article.orderDuration){
            cout << article.numberOfArticel << "\t" << descHelper << " " << article.description << " \t" << stock.actualStock << " \t" << article.costPrice << "€" << " \t" << stock.consumption << " \t" << article.orderDuration << endl;
                totalStockValue += stock.actualStock*article.costPrice;
                reorderPoint = (article.orderDuration * stock.consumption) + 2;
                if(reorderPoint > stock.actualStock){
                    orderProposal = reorderPoint - stock.actualStock;
                    reorder << "\t" << reorderPoint << "\t\t" << orderProposal << endl;
                }else{reorder << "\t" << reorderPoint << "\t\t" << 0 << endl;
            }
        }
    }
            
    cout << "\n\nTotal stock value is: " << totalStockValue << endl;

    database.close();
    reorder.close();

    return 0;
}