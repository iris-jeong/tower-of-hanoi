// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac
#pragma once

#include <string>

#include <vector>
#include "gwindow.h"

#include "disk.h"

class Peg
{
private:
	int mX;
	int mY;
	int mW;
	int mH;
	int xCenter;
    int diskBottom;
    int curTop;
	std::string mColor = "BLACK";
    
    //All the disks that are on 'this' peg
	std::vector<Disk> diskVect;
    
public:
    /**
     Peg Default Constructor
     Input: None
     Output: None
     Side Effects:
        Sets the Peg member variables to empty
     Summary:
        Creates a Peg object
     */
    Peg();
    /**
     Peg Parameterized Constructor
     Input:
        1. An integer with the X-value
        2. An integer with the Y-value
        3. An integer with the Width value
        4. An integer with the Height value
     Output: None
     Side Effects:
        Sets the relevant Peg member variables
     Summary:
        Creates a Peg object
     */
    Peg(int x, int y, int width, int height);

    /**
     Peg Parameterized Constructor
     Input:
        1. An integer with the X-value
        2. An integer with the Y-value
        3. An integer with the Width value
        4. An integer with the Height value
        5. A string with the Color value
     Output: None
     Side Effects:
        Sets the relevant Peg member variables
     Summary:
        Creates a Peg object
     */
    Peg(int x, int y, int width, int height, std::string color);

    /**
     A function that will draw a rectangle that represents the Peg and all of the Disks that are "on" that Peg.
     Input:
        1.  Gwindow by reference
     Output: None
     Side Effects:
        Prints the peg rectangle with its Disks
     Summary:
        A draw function that creates a Peg with its Disks on top
     */
    void draw(GWindow& gw);
    
    /**
     A function that will add a Disk on the Peg
     Input:
        1. Disk object
     Output: None
     Side Effects: The input Disk object will be added to the end of 'diskVect'
     Summary: Adds another disk to a peg.
     */
    void addDisk(Disk d);
    
    /**
     A function that will remove a Disk on the Peg
     Input: None
     Output: Disk object
     Side Effects: Removes Disk from the last index in the diskVect (smallest peg)
     Summary: Removes a Disk from the Peg.
     */
    Disk removeDisk();
    /**
     A function that will print all the Disks on the peg
     Input: none
     Output: none
     Side Effects: Prints all the disks in the vector
     */
    void printDisks();
};

