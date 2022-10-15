// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac
#pragma once

#include "disk.h"
#include "peg.h"
#include "gwindow.h"

#include <vector>

/**
**promptForDisks()**
 @brief A function that prompts the user for the number of Disks to start with (2 to 10 inclusive).
    
  @return int : The number of Disks the user requested.
*/
int promptForDisks();
/**
**promptForPegs()**
  @brief A function that receives the starting Peg and ending Peg numbers (1, 2, or 3).
    
  @params startNum (by reference) : An integer that represents the starting peg number.
  @params endNum (by reference) : An integer that represents the ending peg number.
*/
void promptForPegs(int& startNum, int& endNum);
/**
**promptForPause()**
 @brief A function that uses std::cout to prompt the user for the number of milliseconds to pause between images in the animation (1 to 1,000,000 inclusive).
*/
int promptForPause();
/**
**promptForWindowSize()**
 @brief A function prompts the user for a width and height for the graphics window.

 @param width (by reference) : An integer representing the width of the window size.
 @param height (by reference) : An integer representing the height of the window size.
*/
void promptForWindowSize(int& width, int& height);
/**
**draw()**
 @brief A function that draws all the Pegs.
 
 @param gw (by reference) : A GWindow
 @param pegVect (by reference) : A vector of Pegs
 @param integer : An integer
*/
void draw(GWindow& gw, std::vector<Peg>& pegVect, int milliseconds);
/**
**moveDisk()**
 @brief A function that moves the top-most Disk from the start Peg and adds it to the destination peg.
 
 @param gw (by reference) : A GWindow
 @param pegVect (by reference) : A vector of Pegs
 @param integer : An integer that represents the starting peg
 @param integer : An integer that represents the ending peg
 @param integer : An integer that represents the pause length
*/
void moveDisk(GWindow& gw, std::vector<Peg>& pegVect, int startPegNum, int endPegNum, int pauseLength);
/**
**moveDisk()**
 @brief A function that moves the top-most Disk from the start Peg and adds it to the destination peg.
 
 @param gw (by reference) : A GWindow
 @param pegVect (by reference) : A vector of Pegs
 @param integer : An integer that represents the starting peg
 @param integer : An integer that represents the ending peg
 @param integer : An integer that represents the number of pegs to move
 @param integer : An integer that represents the pause length
**/
void towerSolve(GWindow& gw, std::vector<Peg>& pegVect, int startPegNum, int endPegNum, int numDisks, int pauseLength);

/**
**towerRun()**
 @brief A function to call all the needed functions to get everything running.
 */
int towerRun();

/**
    towerSolveHelper()
 */
void towerSolveHelper(GWindow& gw, std::vector<Peg>& pegVect, int startPegNum, int endPegNum, int midPegNum, int numDisks, int pauseLength);



const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;
