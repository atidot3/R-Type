#ifndef FILEUNIX
# define FILEUNIX

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include "iFile.hpp"

class FileUnix : public IFile
{
public:
    FileUnix();
    FileUnix(const string&);
    void    open(const string &path);
	void    close();
	string  read(int len);
	int     write(const string &buff);

private:
    int     hFile;
    bool    opened;
};

typedef FileUnix AbstractFile;

#endif //FILEUNIX
