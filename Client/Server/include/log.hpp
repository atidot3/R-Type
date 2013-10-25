#ifndef Logger_H
#define Logger_H

#include <fstream>

class Logger {
    public:
        static Logger* Instance();
        bool open(const char* file);
        void log(int level, const char* message);
        bool close();
        
    private:
        Logger() {};
        Logger(Logger const&) {};
        Logger& operator=(Logger const&) {};
        static Logger* m_Instance;
        std::ofstream logFile;
};

#endif