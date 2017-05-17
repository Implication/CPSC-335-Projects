// Assignment 1: Alternating disks problem, left-to-right algorithm                                                                                                                              
// Trajon Felton( YOU NEED TO COMPLETE YOUR NAME )  
// Given 2n alternating disks (dark, light)  the program reads the number of single color disks 
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
        //File Redirection
        disks[i] == '0' ? out << "d " : out << "l ";
        i++;
    }
    out << endl;
    cout << endl;
}
int main() {
  int n, m, k, i;
  char *disks;
  fstream out;
  //Output redirection to lawnmower.txt
  out.open("lawnmower.txt");
  // display the header
  //File Redirection
  out << "CPSC 335-x - Programming Assignment #1" << endl;
  out << "The alternating disks problem: lawnmower algorithm" << endl;
  out << "Enter the number of single color disks (light or dark)" << endl;
  // read the number of disks 
  cin >> n;
  // allocate space for the disks
  //File Redirection
  out << n << endl;
  disks = new char[2*n];
  // set the initial configurations for the disks to alternate 
  for( i=0; i < n; i++) {
    disks[2*i] = '0';
    disks[2*i+1] = '1';
  }
  // print the initial configuration of the list of disks
  //File Redirection
  out << "Initial configuration" << endl;
  print_disks(n,disks,out);
  m = 0; //Initialize our swap count to be zero
  // loop to push light one before darks ones 
  for (k=0;  k < n/2+1 ; k++) {
      //First inner loop, goes left to right
    for (int i = 0; i <= (2 * n) - 2; i++) {
        //Swap when the disk is dark, and the next desk is not dark
        if (disks[i] == '0' && disks[i] != disks[i + 1]) {
            char temp = disks[i];
            disks[i] = disks[i + 1];
            disks[i + 1] = temp;
            m++; //Increment the number of swaps, every time this is true
            }
        }
    //Inner loop goes right to left from the right most disk, to the second to last disk
    for(int j =  2 * n - 1; j >= 1; j--){
        //Swap when the disk is light, and the next disk to its left is dark
          if (disks[j] == '1' && disks[j] != disks[j - 1]) {
            char temp = disks[j];
            disks[j] = disks[j - 1];
            disks[j - 1] = temp;
            m++; //Increment our swap count by one every time this is true.
            }
    }
  }
  // after shuffling them
  //File Redirection
  out << "After moving darker ones to the left" << endl;
  print_disks(n, disks,out);
  // print the total number of moves
  //File Redirection
  out << "Number of swaps is " << m << endl;
  // de-allocate the dynamic memory space
  delete [] disks;
  return EXIT_SUCCESS;
}

