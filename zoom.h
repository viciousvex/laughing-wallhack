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
    CPosition(char, char); // initialize X and Y
};

class CCharacter {
    // A CCharacter contains all the information of one 8x8 bit character on
    // the C64s screen
    CPosition position; // characters initial position on screen
    char character; // character value
    char bg_color; // background color
    char fg_color; // foreground color

public:
    CCharacter(CPosition *, char, char, char);
   
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
#define MAXX 40 // screen has 40 cols
#define MAXY 25 // screen has 25 rows
#define CHARWIDTH 8 // a character is 8 pixels wide
#define CHARHIGHT 8 // a character is 8 pixels tall
    char screen_memory[MAXY*CHARHIGHT][MAXX*CHARWIDTH];
    
};


#endif
