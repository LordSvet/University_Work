#include <iostream>
using namespace std;



///\brief Function for encoding.
///
///Using originalText and password that are input by the user,
///it first checks whether or not the password is longer than the originalText and continues accordingly if it is, by erasing the unneeded letters from password.
///If the password is shorter it goes through a for loop where i goes through every char in originalText and in the case it is a space it erases the rest of the password and reinserts it in the right order.

///@param originalText This is the text that has to be encoded.
///@param passowrd This is the password that is used to encrypt the text.

string encodingProcess(string originalText, string password){ 

    int j = 0;  ///Variable j is used as a counter for the spaces put.
    int x = 0;  ///Variable x is used as a counter as well.
    string encrypted{}; ///Variable encrypted is where result will be stored
    int passSize = password.size(); ///Variable passSize is where the password size will be saved.
    string ogPassword{password}; ///Variable ogPassword is where the original password is used for later use.

    if(passSize < originalText.size()){
        for(int i = 0; i < originalText.size(); i++){
            if(i >= passSize){
                if(originalText[i] != 32){
                    if(password.size() - j >= passSize + ogPassword.size()){
                        passSize += ogPassword.size();
                        password += ogPassword[i - passSize - j];
                    }else
                    password += ogPassword[i - passSize- j];
                }else if(originalText[i] == 32){
                    password += 32;
                    j++;
                }
            }else if(originalText[i] == 32 && i < passSize){
                password.erase(i, passSize);
                for(i; i - j < passSize; i++){
                    if(originalText[i] != 32){
                    password += ogPassword[i - x];
                    }else{
                        password += 32;
                        x++;
                        j++;
                    }
                }
                i--;
            }
        }
    }else if (passSize > originalText.size()){
        password.erase(originalText.size(), passSize);
    }
    string finale{password};
    j = 0;
    while(password[j]){                    ///While loops are there to make password and originalText into lower letters.                   
        password[j] = tolower(password[j]);
        j++;
    }
    j = 0;
    while(originalText[j]){                                  
        originalText[j] = tolower(originalText[j]);
        j++;
    }
    for(int i = 0; i <= originalText.size(); i++){     ///For loop at the end where the letter is first cast into int for its ascii value and substracted 97 to see its number in the alphabet from 0-25 and formula is used.
        if((originalText[i]) != 32){    
                finale[i]  = ((static_cast<int>(originalText[i] - 97)) + (static_cast<int>(password[i]) - 97)) % 26;
                finale[i] += 65;        
        }
        else{ 
                finale[i] = 32;         
            }
    }
    encrypted = finale;
    return encrypted; ///Returns encrypted word.
}

///\brief Function for decoding.
///
///Using encryptedText and password that are input by the user,
///it first checks whether or not the password is longer than the encryptedText and continues accordingly if it is, by erasing the unneeded letters from password.
///If the password is shorter it goes through a for loop where i goes through every char in encryptedText and in the case it is a space it erases the rest of the password and reinserts it in the right order.

///@param encryptedText This is the text that has to be decoded.
///@param passowrd This is the password that is used to find the original text.
string decodingProcess(string encryptedText, string password){  
    int x{0};   ///Variable which is used as a counter in the for loops.
    int j {0};  ///Same as variable x, it is used as a counter.
    string decrypted{}; ///Variable where result will be stored.
    int passSize = password.size(); ///Variable which stores password's length
    string ogPassword{password}; ///Variable storing the original password which will be of use later.

   if(passSize < encryptedText.size()){ 
        for(int i = 0; i < encryptedText.size(); i++){
            if(i >= passSize){
                if(encryptedText[i] != 32){
                    if(password.size() - j >= passSize + ogPassword.size()){
                        passSize += ogPassword.size();
                        password += ogPassword[i - passSize - j];
                        
                    }else
                    password += ogPassword[i - passSize- j];
                }else if(encryptedText[i] == 32){
                    password += 32;
                    j++;
                }

            }else if(encryptedText[i] == 32 && i < passSize){
                password.erase(i, passSize);
                for(i; i - j < passSize; i++){
                    if(encryptedText[i] != 32){
                    password += ogPassword[i - x];
                    }else{
                        password += 32;
                        x++;
                        j++;
                    }
                }
                i--;
            }

        
        }
    }else if (passSize > encryptedText.size()){
        password.erase(encryptedText.size(), passSize);
    }
    j = 0;
    while(encryptedText[j]){    ///While loops are there to change encryptedText and password to upper case letters.                              
        encryptedText[j] = toupper(encryptedText[j]);
        j++;
    }
    j = 0;
    
    while(password[j]){                                  
        password[j] = toupper(password[j]);
        j++;
    }
    string finale{password};
    j = 0;
    
    for(int i = 0; i <= encryptedText.size(); i++){   ///For loop at the end where the letter is first cast into int for its ascii value and substracted 97 to see its number in the alphabet from 0-25 and formula is used.
        if((encryptedText[i]) != 32){    
                int mix = ((static_cast<int>(encryptedText[i] - 65)) - (static_cast<int>(password[i]) - 65));
                if (mix < 0) finale[i] = mix + 26;
                else finale[i]  = mix % 26;
                finale[i] += 97;       
        }
        else{ 
                finale[i] = 32;         
            }
    }
    decrypted = finale;

    return decrypted;
}


///Main method.
///In here the user has the option to choose between encoding and decoding and can input any word and password they want when they run the program.
int main(){
    string originalText{""};
    string password{""};
    string encryptedText{""};
    int input{};

    cout << "Please press 1 for encoding and 2 for decoding:";
    cin >> input;
    cin.ignore();
    switch (input)
    {
    case 1:
        cout << "Please enter text to be encoded: ";
        getline(cin, originalText);
        cout << "Please enter password: ";
        getline(cin, password);
        cout << encodingProcess(originalText, password) << endl;;
        break;
    case 2:
        cout << "Please enter text to be decoded: ";
        getline(cin, encryptedText);
        cout << "Please enter password: ";
        getline(cin, password);
        cout << decodingProcess(encryptedText, password);
        break;
    default:
        cout << "Please restart and enter 1 or 2";
        break;
    }

    return 0;
}
