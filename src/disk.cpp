// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac

#include "disk.h"
Disk::Disk() {
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    mColor = "PINK";
}
Disk::Disk(int x, int y, int width, int height) {
    mX = x;
    mY = y;
    mW = width;
    mH = height;
}
Disk::Disk(int x, int y, int width, int height, std::string color) {
    mX = x;
    mY = y;
    mW = width;
    mH = height;
    mColor = color;
}
void Disk::draw(GWindow &gw) {
    //Set the color
    gw.setColor(mColor);
    
    //Calculate dX, dY
    int dX = mX - (mW / 2);
    int dY = mY - mH;
    
    //Draw the rectangle
    gw.fillRect(dX, dY, mW, mH);
}
void Disk::setX(int x) {
    mX = x;
}
void Disk::setY(int y) {
    mY = y;
}
void Disk::setColor(std::string color) {
    mColor = color;
}
int Disk::getHeight() {
    return mH;
}
int Disk::getY() {
    return mY;
}
std::ostream& operator<<(std::ostream& out, const Disk& disk) {
    out << "x-val: " << disk.mX << std::endl;
    out << "y-val: " << disk.mY << std::endl;
    out << "width: " << disk.mW << std::endl;
    out << "height: " << disk.mH << std::endl;
//    out << disk.diskName << std::endl;
    
    return out;
}


