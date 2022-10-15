// ITP 365 Fall 2022
// HW04 – Towers of Hanoi
// Name: Iris Jeong
// Email: irisjeon@usc.edu
// Platform: Mac
#pragma once

#include <iostream>
#include <string>
#include "gwindow.h"

class Disk
{
private:
    int mX;
    int mY;
    int mW;
    int mH;
    std::string mColor = "BLACK";
    
public:
    std::string diskName;
    /**
    **Disk Default Constructor**
    @brief Constructs a Disk object.
    */
    Disk();
    /**
    **Disk Parameterized Constructor**
     @brief Constructs a Disk object.
     
     @param x : An integer with the X-value.
     @param y : An integer with the Y-value.
     @param width :  An integer with the Width value.
     @param height : An integer with the Height value.
    */
    Disk(int x, int y, int width, int height);
    /**
    **Disk Parameterized Constructor**
     @brief Constructs a Disk object.
      
     @param x : An integer with the x-value.
     @param y : An integer with the y-value.
     @param width :  An integer with the width value.
     @param height : An integer with the height value.
     @param color : A string with the color value.
    */
    Disk(int x, int y, int width, int height, std::string color);

    /**
    **Draw( )**
     @brief A function that will draw a rectangle that represents a Disk.
    
    @param gw : a GWindow by reference.
    */
    void draw(GWindow& gw);

    /**
    **Setters**
     @brief Setters that update the appropriate member variables.
    
     @param x : An integer that sets the x-value.
     @param y : An integer that sets the y-value.
     @param color : A string that sets the color value.
    */
    void setX(int x);
    void setY(int y);
    void setColor(std::string color);
    
    /**
    **Getters**
     @brief Getters that return the appropriate member variables.
    
     @return int : The height of the Disk
     @return int : They y-value of the Disk
    */
    int getHeight();
    int getY();
    
    /**
    **Output Stream Operator**
     @brief An output stream operator to print the Disk information.
     
     @param out : The output stream to display to.
     @param disk : The Disk to display.
     
     @return int : The inputted output stream.
       Displays a Disk like this:
       x-val: 250
       y-val: 250
       width: 300px
       height: 100px
     */
    friend std::ostream& operator<<(std::ostream& out, const Disk& disk);
};
