#pragma once
#include"Board.h"
#include<iostream>
using namespace std;

class Graph {
private:
    int vertArr[305][305]; //the adjacency matrix initially 0
    int count = 0;

public:
    void set_Graph(int arr[34][28]);
    void add_edge(int arr[34][38]);
    Board board;

    Graph();

    // Function to insert a new edge 
    

    // Function to display the BFS traversal 
    void BFS(int start);
};


