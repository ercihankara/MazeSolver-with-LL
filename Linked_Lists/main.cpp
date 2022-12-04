#include <iostream>
#include "Node.h"
#include "utils.hpp"
#include "Left_Hand_Rule.hpp"
#include "LL_wrapper.hpp"

using namespace std;

int main()
{
    Maze maze("input_maze.txt");
    Node<char>* head = (Node<char>*) nullptr;
    LL_wrapper<char> LL(head);

    cout << "First Pass:" << endl;
    LL.print_elements();
    maze.print_state();
    while(!maze.is_solved()){
        LeftHandRule(maze, LL);
        LL.print_elements();
        maze.print_state();
        if(maze.is_solved())
            break;
        cout << endl;
    }
    cout << endl;

    // reinitialize the maze
    new (&maze) Maze("input_maze.txt");
    cout << "Second Pass:" << endl;
    LL.print_elements();
    maze.print_state();
    cout << endl;

    while(!maze.is_solved()){
        LHR_stage_two(maze, LL);
        LL.print_elements();
        maze.print_state();
        if(maze.is_solved())
            break;
        cout << endl;
    }

    return 0;
}
