#include <iostream>
#include <cstdlib>
#include "LL_wrapper.hpp"
#include "Maze.h"
#include "Node.h"
// implement Left Hand Rule:

using namespace std;

template <class T>
void LeftHandRule(Maze& maze, LL_wrapper<T>& LL){
    // acting as a stack
    if(maze.can_move_left()){
        maze.move_left();
        if(LL.peek_rear() != 'B')
            LL.push_rear('L');
        else{
            LL.pop_rear();
            switch (LL.pop_rear()){
                case 'F':
                    LL.push_rear('R');
                    break;
                case 'R':
                    LL.push_rear('B');
                    break;
                case 'L':
                    LL.push_rear('F');
                    break;
            }
        }
    }
    else if(maze.can_move_forward()){
        maze.move_forward();
        if(LL.peek_rear() != 'B'){
            LL.push_rear('F');
        }
        else{
            LL.pop_rear();
            switch (LL.pop_rear()){
                case 'L':
                    LL.push_rear('R');
                    break;
                case 'F':
                    LL.push_rear('B');
                    break;
            }
        }
    }
    else if(maze.can_move_right()){
        maze.move_right();
        if(LL.peek_front() != 'B')
            LL.push_rear('R');
        else{
            LL.pop_rear();
            switch (LL.pop_rear()){
                case 'L':
                    LL.push_rear('B');
                    break;
            }
        }
    }
    else{
        maze.move_back();
        LL.push_rear('B');
    }
}

template <class T>
void LHR_stage_two(Maze& maze, LL_wrapper<T>& LL){
    T temp;
    if(!LL.is_empty()){
        temp = LL.pop_front();
        if(temp == 'L')
            maze.move_left();
        else if(temp == 'F')
            maze.move_forward();
        else if(temp == 'R')
            maze.move_right();
        else
            cout << "ERROR" << endl;
    }
}
