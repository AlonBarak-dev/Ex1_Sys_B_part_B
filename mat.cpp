#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// define a namespace, ariel
namespace ariel {


    string even(char c1, char c2, int times, int cols){
        /*
            this method return a custom string for 
            even rows.
        */
        string res_string;
        // initialize the string with the first char
        for (int i = 0; i < cols; i++)
        {
            res_string.push_back(c1);
        }
        // add the second char in jumps of 2 from the start and from the end as well 
        for(int i = 0; i < times; i++){
            
            res_string.at(2*i + 1) = c2;
            res_string.at(cols - 2*i - 2) = c2;
        }
        // return the new line after the changes
        return res_string;
    }

    string odd(char c1, char c2, int times, int cols){
        /*
            this method return a custom string for 
            odd rows.
        */

        string res_string;
        // initialize the string with the second char
        for(int i = 0; i < cols; i++){
            res_string.push_back(c2);
        }
        // add the first char in jumps of 2 from start and from the end as well
        for(int i = 0; i < times; i++){
            
            res_string.at(2*i) = c1;
            res_string.at(cols - 2*i - 1) = c1;
        }
        // return the new line after the changes 
        return res_string;
    }


    string mat(int col, int row, char c1, char c2){

        // ERROR handling section
        // throw an error for invalid arguments, such as: even numbers and negative numbers
        
        if ( (row % 2 == 0) || (col % 2 == 0)) {
            // even numbers detected
            throw runtime_error("Rows and Cols size is invalid, try odd values");
        }
        if ((row < 0) || (col < 0)) {
            // negative numbers detected
            throw runtime_error("Rows and Cols size is invalid, try positive values");
        }
        int const low_bound = 33;
        int const upper_bound = 126;
        if ((c1 > upper_bound) || (c1 < low_bound) || (c2 > upper_bound) || (c2 < low_bound)){
            // non-ascii letters
            throw invalid_argument("Symbols must be an Ascii chars");
        }

        string res_string;      // the final string, representing the carpet 
        string buttom_half;     // a string that holds the buttom half of the carpet
        string line;        

        // if the carpet has only one culomn, return the first char, row times
        if (col == 1)
        {
            // loop over the rows and add the char
            for (int i = 0; i < row; i++)
            {
                res_string.push_back(c1);
            }
            // finally, return the carpet's string
            return res_string;
        }
        
        // in case the carpet has more than one culomn
        int times = 0;      
        // loop until the middle row
        for (int i = 0; i < (row / 2 + 1); i++)
        {
            
            times = (i + 1) / 2;    // number of appearances of char1 or char2

            if(i % 2 == 0){
                // even row index
                line = even(c1, c2, times, col);
            }
            else{
                // odd row index
                line = odd(c1, c2, times, col);
            }
            // add the given row to the existing carpet's string
            res_string.append(line);
            // calculate the buttom half of the carpet by inserting the upper half backwards
            if(i != int(row / 2)){
                buttom_half.insert(0, "\n");
                buttom_half.insert(0, line);
            }
            if(i != row - 1){
                // step one line down
                res_string.append("\n");
            }
        }
        // add the buttom half of the carpet to the upper half and return the full carpet's string
        res_string.append(buttom_half);
        return res_string;
    }    

}


