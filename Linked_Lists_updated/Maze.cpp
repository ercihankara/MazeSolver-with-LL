// Ercihan Kara - 2375160
/////////////// functions for Maze class ///////////////
#include "Maze.h"
#include <iostream>
#include "get_maze_file.h"

using namespace std;

// constructor
Maze::Maze(string file_name){
    current_maze = get_maze_file(file_name);
    nrow = num_row;
    ncol = num_col;
    agency_pos = new int[2];
    next_agency_pos = new int[2];
    set_agency_pos();
    next_orient = '0'; // 0 for a short time
    solved = false; // label to check the solution's completion
}

// copy constructor
Maze::Maze(const Maze& prev_Maze){
    current_maze = prev_Maze.get_current_maze();
    nrow = prev_Maze.get_nrow();
    ncol = prev_Maze.get_ncol();
    agency_pos = prev_Maze.get_agency_pos();
}

// get current maze
char** Maze::get_current_maze() const{
    return current_maze;
}

// return number of columns to be used
int Maze::get_nrow() const{
    return nrow;
}

// return number of columns to be used
int Maze::get_ncol() const{
    return ncol;
}

// get current position
int* Maze::get_agency_pos() const{
    return agency_pos;
}

// get agency's current orientation
char Maze::get_curr_orient() const{
    return curr_orient;
}

// get next position
int* Maze::get_next_agency_pos() const{
    return next_agency_pos;
}

// get agency's next orientation
char Maze::get_next_orient() const{
    return next_orient;
}

// get agency's current position
void Maze::set_agency_pos(){
    // traverse the maze to find one of {W, N, S, E}
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            if((current_maze[i][j] == 'W') || (current_maze[i][j] == 'N') || (current_maze[i][j] == 'S') || (current_maze[i][j] == 'E')){
                agency_pos[0] = i;
                agency_pos[1] = j;
                //cout << current_maze[agency_pos[0]][agency_pos[1]] << endl;
                curr_orient = current_maze[agency_pos[0]][agency_pos[1]];
            }
        }
    }
}

// check conditions
bool Maze::can_move_left(){

    switch (current_maze[agency_pos[0]][agency_pos[1]]){

        case 'E':
            next_agency_pos[0] = agency_pos[0]-1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'N';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'W':
            next_agency_pos[0] = agency_pos[0]+1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'S';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'N':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]-1;
            next_orient = 'W';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'S':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]+1;
            next_orient = 'E';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        default:
            return false;
    }
 }

bool Maze::can_move_forward(){

    switch (current_maze[agency_pos[0]][agency_pos[1]]){

        case 'E':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]+1;
            next_orient = 'E';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'W':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]-1;
            next_orient = 'W';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'N':
            next_agency_pos[0] = agency_pos[0]-1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'N';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'S':
            next_agency_pos[0] = agency_pos[0]+1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'S';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        default:
            return false;
    }
 }

bool Maze::can_move_right(){

    switch (current_maze[agency_pos[0]][agency_pos[1]]){

        case 'E':
            next_agency_pos[0] = agency_pos[0]+1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'S';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'W':
            next_agency_pos[0] = agency_pos[0]-1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'N';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'N':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]+1;
            next_orient = 'E';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'S':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]-1;
            next_orient = 'W';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        default:
            return false;
    }
 }

bool Maze::can_move_back(){

    switch (current_maze[agency_pos[0]][agency_pos[1]]){

        case 'E':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]-1;
            next_orient = 'W';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'W':
            next_agency_pos[0] = agency_pos[0];
            next_agency_pos[1] = agency_pos[1]+1;
            next_orient = 'E';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'N':
            next_agency_pos[0] = agency_pos[0]+1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'S';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        case 'S':
            next_agency_pos[0] = agency_pos[0]-1;
            next_agency_pos[1] = agency_pos[1];
            next_orient = 'N';
            return (current_maze[next_agency_pos[0]][next_agency_pos[1]] == '.' || current_maze[next_agency_pos[0]][next_agency_pos[1]] == 'T') ? true: false;
            break;
        default:
            return false;
    }
}

// turn and move the agent
void Maze::move_left(){
    int checker = -1;
    try{
        if(can_move_left()){
            current_maze[agency_pos[0]][agency_pos[1]] = '.';
            for(int i=0; i<2; i++)
                agency_pos[i] = next_agency_pos[i];
            if(current_maze[agency_pos[0]][agency_pos[1]] == 'T')
                solved = true;
            current_maze[agency_pos[0]][agency_pos[1]] = next_orient;
        }

        else
            throw checker;
    }
    catch (int checker){
        cout << "Not a valid operation!" << endl;
    }
}

void Maze::move_forward(){
    int checker = -1;
    try{
        if(can_move_forward()){
            current_maze[agency_pos[0]][agency_pos[1]] = '.';
            for(int i=0; i<2; i++)
                agency_pos[i] = next_agency_pos[i];
            if(current_maze[agency_pos[0]][agency_pos[1]] == 'T')
                solved = true;
            current_maze[agency_pos[0]][agency_pos[1]] = next_orient;
        }

        else
            throw checker;
    }
    catch (int checker){
        cout << "Not a valid operation!" << endl;
    }
}

void Maze::move_right(){
    int checker = -1;
    try{
        if(can_move_right()){
            current_maze[agency_pos[0]][agency_pos[1]] = '.';
            for(int i=0; i<2; i++)
                agency_pos[i] = next_agency_pos[i];
            if(current_maze[agency_pos[0]][agency_pos[1]] == 'T')
                solved = true;
            current_maze[agency_pos[0]][agency_pos[1]] = next_orient;
        }

        else
            throw checker;
    }
    catch (int checker){
        cout << "Not a valid operation!" << endl;
    }
}

void Maze::move_back(){
    int checker = -1;
    try{
        if(can_move_back()){
            current_maze[agency_pos[0]][agency_pos[1]] = '.';
            for(int i=0; i<2; i++)
                agency_pos[i] = next_agency_pos[i];
            if(current_maze[agency_pos[0]][agency_pos[1]] == 'T')
                solved = true;
            current_maze[agency_pos[0]][agency_pos[1]] = next_orient;
        }

        else
            throw checker;
    }
    catch (int checker){
        cout << "Not a valid operation!" << endl;
    }
}

// print the current state of the maze
void Maze::print_state() const{
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            cout << current_maze[i][j];
        }
        cout << endl;
    }
}

// check whether maze is solved or not
bool Maze::is_solved() const{
    if(solved == true){
        cout << "Maze is solved." << endl;
        return true;
    }
    else
        return false;
}

// destructor
Maze::~Maze(){
    for(int i=0; i<nrow; i++)
        delete[] current_maze[i];
    delete[] current_maze;
    delete[] agency_pos;
    delete[] next_agency_pos;
}
