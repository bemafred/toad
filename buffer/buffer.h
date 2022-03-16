/*
** buffer.h
**
** Implements a text buffer.
*/

#ifndef _buffer_h
#define _buffer_h

#include <string>
#include <vector>

class buffer
{
    public:

        buffer();
        buffer(const char* filePath);

        ~buffer();

    private:
        bool _insert
;
        string _filePath;
        vector<string> _rows;
        int _column;
        int _row;

}

#endif
