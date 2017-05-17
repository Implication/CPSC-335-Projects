// Assignment 1: Alternating disks problem, left-to-right algorithm   
// Trajon Felton ( YOU NEED TO COMPLETE YOUR NAME )  
// Given 2n alternating disks (dark, light) the program reads the number of single color disks 
// (light or dark), arranges the disks in the correct order and outputs the number of swaps 
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark 
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,  
// and an integer m representing the number of moves to move the dark ones after the light ones  

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;
void print_disks(int n, char *disks, fstream& out){
    int i = 0;
    while(i < 2 * n ){
        disks[i] == '0' ? out << "d " : out << "l ";
        i++;
    }
    out << endl;
}
// YOU NEED TO IMPLEMENT THIS FUNCTION
// function to print the list of disks, given the number of single color disks and the actual list  
// n represents the number of single color disks 
// disks represents the list of disks (index 0 being the first disk) where
// 0 = a light color disks 
// 1 = a dark color disks
int main() {
  int n, m, k, i;
  char *disks;
  fstream out;
  out.open("left-to-right.txt");
  // display the header 
  out << endl << "CPSC 335-x - Programming Assignment #1" << endl;
  out << "The alternating disks problem: left-to-right algorithm" << endl;
  out << "Enter the number of single color disks (light or dark)" << endl;
  // read the number of disks 
  cin >> n;
  out << n << endl;
  // allocate space for the disks                                                                                                                                                                        
  disks = new char[2*n];
  // set the initial configurations for the disks to alternate 
  for( i=0; i < n; i++) {
    disks[2*i] = '0';
    disks[2*i+1] = '1';
  }
  // print the initial configuration of the list of disks  
  out << "Initial configuration" << endl;
  print_disks(n,disks,out);
  // loop to push light one before the darks ones 
  m = 0; //Number of swaps
  for (k=0;  k < n ; k++) { //Outer loop to loop until n - 1
      for(int i = 0; i <= (2 * n) - 2; i++){ //inner loop for swapping
          //Swap if the disk is equal to a dark disk, and the next disk is light
          if(disks[i] == '0' && disks[i] != disks[i + 1]){ 
          char temp = disks[i];
          disks[i] = disks[i+1];
          disks[i+1] = temp;
          m++; //Increment the number of swaps every time this is true.
          }
      }
  }
  print_disks(n, disks,out);
  // print the total number of moves 
  out << "Number of swaps is " << m << endl;
  // de-allocate the dynamic memory space 
  delete [] disks;
  return EXIT_SUCCESS;
}

