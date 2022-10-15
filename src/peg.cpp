// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac

#include "peg.h"
Peg::Peg() {
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    mColor = "YELLOW";
}
Peg::Peg(int x, int y, int width, int height) {
    mX = x;
    mY = y;
    mW = width;
    mH = height;
}
void Peg::draw(GWindow& gw) {
    //Set the color.
    gw.setColor(mColor);
    
    //Calculate the top left (dX and dY).
    int dX = mX - (mW / 2);
    int dY = mY - mH;
    
    //Draw the peg.
    gw.fillRect(dX, dY, mW, mH);
    
    //Initialize the location of the first peg. (Where the bottom of the first peg goes).
    diskBottom = mY;
    
    //Draw each of the disks on the peg.
    for(int i = 0; i < diskVect.size(); i++) {
        //Set the bottom
        diskVect[i].setY(diskBottom);
        
        //Draw the Disk
        diskVect[i].draw(gw);
        
        //Set the new bottom for the next peg
        diskBottom = diskVect[i].getY() - diskVect[i].getHeight();
    }
}
void Peg::addDisk(Disk d) {
    //Set mX and mY of 'd' to be at the center coordinate of the peg.
    d.setX(mX);
    d.setY(mY);
    
    //Add the disk to the vector.
    diskVect.push_back(d);
}
Disk Peg::removeDisk() {
    //Retrieve the last Disk in the vector.
    Disk lastDisk = diskVect.back();
    
    //Remove the last Disk from the vector.
    diskVect.pop_back();
    
    //Return the Disk that was removed.
    return lastDisk;
}
void Peg::printDisks() {
    int i = 0;
    for(Disk d: diskVect) {
        std::cout << "Disk " << i << ": " << d << std::endl;
        i++;
    }
}
