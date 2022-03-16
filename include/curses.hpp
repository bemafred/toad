#ifndef _curses_hpp
#define _curses_hpp

#include <stdlib.h>
#include <curses.h>
#include <signal.h>

namespace curses
{

class window 
{
    public:

        static window stdscr;
        static window curscr;

        window();
        ~window();


    private:



};

}

#endif
