#include <iostream>
#include "mat.hpp"

using namespace std;

int main(){

    int cols;
    int rows;
    char c1, c2;
    while (true)
    {
        try{
            cout << "Please enter the width of the carpet: " << endl;
        cin >> cols;
        cout << "please enter the height of the carpet: " << endl;
        cin >> rows;
        cout << "Please enter the first symbole for your carpet" << endl;
        cin >> c1;
        cout << "Please enter the second symbole for your carpet" << endl;
        cin >> c2;
        string mat = ariel::mat(cols,rows,c1,c2);
        cout << "Enjoy your new Carpet!" << endl;
        cout << mat << endl;
        }
        catch (exception & ex){
            cout << "   cought exception: " << ex.what() << endl;
        }
        
    }
    
        
return 0;




}