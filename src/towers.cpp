// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac

#include "towers.h"
#include <sstream>

int promptForDisks() {
    //Prompt user for the number of Disks to start with.
    int numDisks;
    std::cout << "Enter the number of disks you'd like to start with (2-10): " << std::endl;
    std::cin >> numDisks;
    
    //Check if valid number of disks.
    while(numDisks < MINDISKS || numDisks > MAXDISKS) {
        std::cout << "Please enter a valid number of disks (2-10): " << std::endl;
        std::cin >> numDisks;
    }
    //Return number of disks user requested.
    return numDisks;
}

void promptForPegs(int& startNum, int& endNum) {
    //Prompt user for a starting peg number.
    std::cout << "Enter a starting peg number (1-3): " << std::endl;
    std::cin >> startNum;
    
    //Check if valid.
    while(startNum < 1 || startNum > 3) {
        std::cout << "Please enter a valid starting peg number (1-3): " << std::endl;
        std::cin >> startNum;
    }
    
    //Prompt user for an ending peg number.
    std::cout << "Enter an ending peg number (1-3): " << std::endl;
    std::cin >> endNum;
    
    //Check if valid.
    while(endNum < 1 || endNum > 3) {
        std::cout << "Please enter a valid end peg number (1, 2, or 3): " << std::endl;
        std::cin >> endNum;
    }
    //Check that start != end.
    while(startNum == endNum) {
        std::cout << "Please enter a starting peg number and ending peg number that are not equal: " << std::endl;
        std::cout << "Enter a starting peg number (1-3): " << std::endl;
        std::cin >> startNum;
        //Enter start peg index.
        while(startNum < 1 || startNum > 3) {
            std::cout << "Please enter a valid starting peg number (1-3): " << std::endl;
            std::cin >> startNum;
        }
        //Enter end peg index
        std::cout << "Enter an ending peg number (1-3): " << std::endl;
        std::cin >> endNum;
        while(endNum < 1 || endNum > 3) {
            std::cout << "Please enter a valid end peg number (1, 2, or 3): " << std::endl;
            std::cin >> endNum;
        }
    }
}

int promptForPause() {
    int milliseconds;
    
    //Prompt the user for the number of milliseconds to pause between images in the animation.
    std::cout << "Enter the number of milliseconds to pause (1-1000000): " << std::endl;
    std::cin >> milliseconds;
    //Check if valid.
    while(milliseconds < 1 || milliseconds > 1000000) {
        std::cout << "Please enter a valid number between 1-1000000: " << std::endl;
        std::cin >> milliseconds;
    }
    return milliseconds;
}

void promptForWindowSize(int& width, int& height) {
    //Prompt user for width
    std::cout << "Enter screen width (800-4096): " << std::endl;
    std::cin >> width;
    //Check if valid
    while(width < MINSCREENWIDTH || width > MAXSCREENWIDTH) {
        std::cout << "Please enter a valid width between " << MINSCREENWIDTH << " and " << MAXSCREENWIDTH << std::endl;
        std::cin >> width;
    }
    
    //Prompt user for height
    std::cout << "Enter screen height (600-2160): " << std::endl;
    std::cin >> height;
    //Check if valid
    while(height < MINSCREENHEIGHT || height > MAXSCREENHEIGHT) {
        std::cout << "Please enter a valid width between " << MINSCREENHEIGHT << " and " << MAXSCREENHEIGHT << std::endl;
        std::cin >> height;
    }
}

void draw(GWindow& gw, std::vector<Peg>& pegVect, int milliseconds) {
    //Clear the graphics currently in window
    gw.clear();
    //Draw all the pegs
    for(int i = 0; i < pegVect.size(); i++) {
        pegVect[i].draw(gw);
    }
    //Use pause function
    pause(milliseconds);
}

void moveDisk(GWindow& gw, std::vector<Peg>& pegVect, int startPegNum, int endPegNum, int pauseLength) {
    
    //Retrieve the top-most Disk from the start peg.
    Disk topDisk = pegVect[startPegNum - 1].removeDisk();

    //Take the disk that was removed from start peg and add it to the end peg.
    pegVect[endPegNum - 1].addDisk(topDisk);

    //Draw.
    draw(gw, pegVect, pauseLength);
}

void towerSolve(GWindow& gw, std::vector<Peg>& pegVect, int startPegNum, int endPegNum, int numDisks, int pauseLength) {
        //Calculate the temporary peg index.
        //3 - (index of start peg + index of end peg) = index of temp peg;
        int tempPegNum = 6 - (startPegNum + endPegNum);

        //If there are no more disks, do nothing.
        if(numDisks == 0) {
            return;
        }
        //Move n-1 disks to the temp peg.
        towerSolve(gw, pegVect, startPegNum, tempPegNum, numDisks-1, pauseLength);
    
        //Move the last disk from start to end peg.
        moveDisk(gw, pegVect, startPegNum, endPegNum, pauseLength);
    
        //Move n-1 disks from the temp peg to the end peg.
        towerSolve(gw, pegVect, tempPegNum, endPegNum, numDisks-1, pauseLength);

}

int towerRun() {
    
    //Create variables to hold user input.
    int numDisks, startPegNum, endPegNum, milliseconds, windowWidth, windowHeight;
    
    //Run prompts to get user input.
    numDisks = promptForDisks();
    promptForPegs(startPegNum, endPegNum);
    
    //Get how many milliseconds user wants to wait between drawings.
    milliseconds = promptForPause();
    
    //Get how big user wants window size.
    promptForWindowSize(windowWidth, windowHeight);
    
    //--* Create the GWindow with 3 Peg Objects *--
    GWindow gw(windowWidth, windowHeight);
    // a) Create 3 Pegs and add them to a vector of pegs.
    std::vector<Peg> pegVect;
    //Calculate the bottom center for the first peg.
    int pegSpace;
    //Take the screen width and divide it by the number of pegs(3) to determine how much space each peg has on the screen.
    pegSpace = windowWidth / NUMPEGS;
    //Divide it by 2 to find the center of each space the peg has. This will be bottom center of each peg.
    int xCenter = pegSpace / 2;
    
    //Add three pegs to the vector
    for(int i = 0; i < 3; i++) {
        pegVect.push_back(Peg(xCenter, windowHeight, 30, 500));
        //Update the next peg's bottom center.
        xCenter += pegSpace;
    }
    
    // b) Add Disks to the user-given starting peg
    //Set the disk width and height
    int diskWidth = (windowWidth / 3) - 50;
    int diskHeight = 50;
    
    //Create the Disks and add to starting peg
    for(int i = 0; i < numDisks; i++) {
        pegVect[startPegNum-1].addDisk(Disk(windowWidth, windowHeight, diskWidth, diskHeight, "PINK"));
        diskWidth -= 50;
    }

    towerSolve(gw, pegVect, startPegNum, endPegNum, numDisks, milliseconds);


}
