#ifndef Logger_H
#define Logger_H

#include <string>
#include <fstream>

class Logger {
    public:
        static Logger* Instance();
        bool open(const char* file);
//        void log(int level, const char* message);
		void log(int level, std::string message);
        bool close();
        
    private:
        Logger() {};
        Logger(Logger const&) {};
        Logger& operator=(Logger const&) {};
        static Logger* m_Instance;
        std::ofstream logFile;
};

#endif