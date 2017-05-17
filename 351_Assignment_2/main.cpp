// Assignment 2: Topology recognition problem                                   
// Trajon Felton                                                                   
// Given a network with n>3 nodes and a weight matrix W[0..n−1, 0..n−1] of      
// positive integers, of a weighted, connected undirected graph modeling        
// a network, decide whether the network is one of the topologies, if any:      
// ring, star, fully connected mesh. Note: represent infinity by the value 100.
// INPUT: a positive integer n and a list of n^2 positive values          
// OUTPUT: message "ring" or "star" or "complete" or "neither"                  

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <cstdio>

using namespace std;
int main() {
  int n, i, j, count, center;
  int W[100][100];
  bool cond;

  // display the header                                                         
  cout << endl << "CPSC 335-x - Programming Assignment #2" << endl;
  cout << "Topology recognition algorithm" << endl;
  cout << "Enter the number of nodes in the topology" << endl;
  // read the number of nodes                                                   
  cin >> n;
  // read the weight matrix                                                     
  cout << "Enter the positive weights, 100 for infinity" << endl;
  for(i=0; i < n; i++)
   for(j=0; j < n; j++)
      cin >> W[i][j];

  
  // Start the chronograph to time the execution of the algorithm               
  auto start = chrono::high_resolution_clock::now();

  cout <<"The topology is"<< endl;

  cond = true;
  bool edgeExists[n] = {false};
  int indicies[n] = {0};
  for (i=0;  i < n ; i++) {
      for(j = 0; j < n; j++){
          if(W[i][j] != 0 && W[i][j] != 100){
              if(W[i][j] == W[j][i]){
              if(edgeExists[j] == true && indicies[j] == 2){
                  cond = false;
                  break;
              }
              else{
                  indicies[j] = indicies[j] + 1;
                  if(indicies[j] == 2)
                      edgeExists[j] = true;
              }
          }
      }
  }
  }
  if(cond)
  for(i = 0; i < n; i++){
      if(edgeExists[i] != true || indicies[i] != 2){
          cond = false;
          break;
      }
  }
 
 if (cond) {
    cout <<"ring" << endl;
    auto end = chrono::high_resolution_clock::now();
    int microseconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
    double seconds = microseconds
    cout << "elapsed time: " << seconds << " seconds" << endl;
    return EXIT_SUCCESS;
  }

  cond = true;
  center = 0;
  // loop to check whether the topology is a star                               
  for (i=0;  i < n ; i++) {
      int ind = 0;
      for(j = 0; j < n; j++){
          if(W[i][j] != 0 && W[i][j] != 100){
              if(W[i][j] == W[j][i])
              ind++;
          }
      }
      if(ind > 1 && ind < (n - 1)){
          cond = false;
          break;
      }
      if(ind == (n-1))
          center = center + 1;
  }

  if (cond && (center == 1)) {
    cout <<"star" << endl;
    auto end = chrono::high_resolution_clock::now();
    int microseconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
    double seconds = microseconds / 1E6;
    cout << "elapsed time: " << seconds << " seconds" << endl;
    return EXIT_SUCCESS;
  }

  cond = true;
  // loop to check whether the topology is a fully connected mesh 
  for (i=0;  i < n ; i++) {
      int ind = 0;
      for(j = 0; j < n; j++){
          if(W[i][j] != 0 && W[i][j] != 100){
              ind++;
          }
      }
      if(ind != n - 1){
          cond = false;
          break;
      }
  }

  if (cond)
    cout << "fully connected mesh" << endl;
  else
   cout << "neither" << endl;

  // End the chronograph to time the loop                                       
  auto end = chrono::high_resolution_clock::now();
  int microseconds = chrono::duration_cast<chrono::microseconds>(end-start).count();
  double seconds = microseconds / 1E6;
  cout << "elapsed time: " << seconds << " seconds" << endl;

  return EXIT_SUCCESS;
}


