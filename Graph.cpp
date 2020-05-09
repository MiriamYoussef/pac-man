#include "Graph.h"

 void Graph::set_Graph(int arr[34][28]) {
    int i, j;
    for (i = 0; i < 304; i++) {
        for (j = 0; j < 304; j++) {
             vertArr[i][j] =0;
        }
   
    }
}

 Graph::Graph()
 {

 }


 void Graph::add_edge(int arr [34][38])
 {
     for (int i = 0; i < 34; i++)
     {
         for (int j = 0; j < 28; j++)
         {
             if (arr[i][j]>=0)
             {
                
                         vertArr[i][j] == 1;
                     
                 
             }
         }
     }
 }
