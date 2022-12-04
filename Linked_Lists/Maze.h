// Ercihan Kara - 2375160
// create Maze class
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class Maze
{
    private:
        // dynamic maze creation
        char** current_maze;
        int nrow;
        int ncol;
        int* agency_pos;
        int* next_agency_pos;
        char curr_orient;
        char next_orient;
        bool solved;

    public:
        // the constructor for the Maze class
        Maze(string file_name);
        // copy constructor
        Maze(const Maze& prev_Maze);

        // set agency's current position
        void set_agency_pos();
        // get agency's current position
        int* get_agency_pos() const;
        // get agency's current orientation
        char get_curr_orient() const;
        // get agency's next position
        int* get_next_agency_pos() const;
        // get agency's next orientation
        char get_next_orient() const;


        // check the validity of a motion
        bool can_move_left();
        bool can_move_forward();
        bool can_move_right();
        bool can_move_back();

        // get the private variables
        char** get_current_maze() const;
        int get_nrow() const;
        int get_ncol() const;

        // turn and move the agent
        void move_left();
        void move_forward();
        void move_right();
        void move_back();

        // print current form of maze
        void print_state() const;
        bool is_solved() const;

        // destructor
        ~Maze();
};


