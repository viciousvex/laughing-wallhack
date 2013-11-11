//
//  zoom.h
//  
//
//  Created by Alexander Schwab on 11.11.13.
//
//

#ifndef _zoom_h
#define _zoom_h

#define MAXZ 255

class CPosition {
    // Stores a position on screen
    char x;
    char y;
public:
    CPosition(char, char);
};

class CCharacter {
    // A CCharacter contains all the information of one 8x8 bit character on
    // the C64s screen
    CPosition position; // characters initial position on screen
    char character; // character value
    char bg_color; // background color
    char fg_color; // foreground color

public:
    CCharacter(char, char, char, char, char);
   
};

class CFlight {
    // Contains the route, speed and current position of an object
    char speed; // speed with which the object travels
    char position; // current position in the flightroute
    CPosition zposition[MAXZ]; // all positions an object is going to step through
    
public:
    CFlight();
};

class CScreen {
    // The screen representation contains characters
};


#endif
