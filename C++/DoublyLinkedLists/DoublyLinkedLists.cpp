#include <iostream>

using namespace std;


///Creating structure DListElem which contains the value and the pointers to next and previous element.
///
struct DListElem{
        int val;
        DListElem* next;
        DListElem* prev;
    };
///Creating structure DList which contains the pointers to the first and last element of the list.
///
struct DList{
        DListElem* first;
        DListElem* last;
    }; 

///InitializeDList creates an empty list.
///dl is the DList to create a new list
void initializeDList(DList& dl){
    dl.first = NULL;
    dl.last = NULL;
};
///Checks if the list is empty and if it is it returns true.
/// dl is the input DList
bool isEmpty(DList dl){
    if(dl.first == NULL && dl.last == NULL){
        return true;
    }
    return false;
}

///Inserts an element at the start of the list.
///I use pointer *frog as a helper to find and put the correct value in front.
///  val This contains the value that will be inserted.
void put(DList& dl, int val){
    DListElem *frog = new DListElem;
    if(isEmpty(dl)){
        frog->val = val;
        dl.first = frog;
        dl.last = frog;
        frog->next = NULL;
        frog->next = NULL;
    }else{
    frog->val = val;
    dl.first->prev = frog;
    frog->next = dl.first;
    dl.first = frog;
    frog->prev = NULL;
    }
}

///Get's the last element of the list and saves it into val, then removes it from the list.
///First it checks if its empty then if it isn't checks if its only one element and proceeds accordingly using 
///the delete function to release it from memory.
/// &val Makes sure that the value stays saved after the function ends.  
bool get(DList& dl, int &val){
    if(isEmpty(dl)){
        return false;
    }
    else if(dl.first == dl.last){
        val = dl.first->val;
        delete dl.first;
        dl.first = NULL;
        dl.last = NULL;
   }else if(isEmpty(dl) == false){
        val = dl.last->val;
        dl.last = dl.last->prev;
        delete (*dl.last).next;
        dl.last->next = NULL;
    }
    return true;
}

///In the main class I just use the one from the example you gave us.
///
int main(int argc, char* argv[])
{
  DList queue;

  initializeDList(queue);

//   insert 5 values
  for (int i = 1; i <= 5; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }

  //remove 3 values and print them to console
  for (int j = 1; j <= 3; j++) {
    int value;
    if (get(queue, value))
       cout << "     get: " << value << endl;
  }

 // cout << "Laenge: " << dlistLength(queue) << endl;
  
  //insert 5 values 
  for (int i = 6; i <= 10; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }

 // cout << "Laenge: " << dlistLength(queue) << endl;

  //remove all values and print them
  while(!isEmpty(queue)) {
    int value;
    get(queue, value);
    cout << "     get: " << value << endl;
  }

  cin.sync(); cin.get();
  return 0;
}
