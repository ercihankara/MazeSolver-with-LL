// Ercihan Kara - 2375160
#include <fstream>
#include <iostream>
// default row and column assignments, global
int num_row = 0;
int num_col = 0;

using namespace std;
// read the maze from file
char** get_maze_file(string file_name){

    ifstream input_file; /* input file stream */
    input_file.open(file_name);

    int nrow, ncol; /* number of rows and columns */
    input_file >> nrow >> ncol; /* read the size from file */
    num_row = (int) nrow; // casting
    num_col = (int) ncol; // casting

    char** state = new char*[nrow];
    for(int i = 0; i < nrow; i++) {
        // Declare a memory block of size ncol
        state[i] = new char[ncol];
    }

    for(int i=0; i<nrow; ++i){
        for(int j=0; j<ncol; ++j){
            input_file >> state[i][j];
        }
    }

    input_file.close();
    return state;
}
