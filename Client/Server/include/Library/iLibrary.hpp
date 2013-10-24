#ifndef ILIBRARY
# define ILIBRARY

#include <string>
#include "libraryException.hpp"

using std::string;

class ILibrary
{
public:
    typedef void*   (*voidFuncPtr)();
    virtual ~ILibrary() {};

    template<typename ptrType>
    ptrType             getSym(const string &name)
    {
        return (reinterpret_cast<ptrType>(getVoidSym(name)));
    }
    virtual voidFuncPtr      getVoidSym(const string &name) = 0;
};

#ifdef WIN32
  #include "libraryWindows.hpp"
#else
  #include "libraryUnix.hpp"
#endif

#endif //ILIBRARY
