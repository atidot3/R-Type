#include <iostream>
#include "log.hpp"

Logger* Logger::m_Instance = NULL;
    
Logger* Logger::Instance() {
    if (!m_Instance) 
        m_Instance = new Logger;
        
    return m_Instance;
}

bool Logger::open(const char* file) {
    logFile.open(file);
	return true;
}

void Logger::log(int level, const char* message)
{
    switch (level) {
        case 0:
            logFile << "Debug - " << __DATE__ << " " << __TIME__ << " | " << message << std::endl;
            break;
        case 1:
            logFile << "Warning - " << __DATE__ << " " << __TIME__ << " | "  << message << std::endl;
            break;
        case 2:
            logFile << "Critical - " << __DATE__ << " " << __TIME__ << " | "  << message << std::endl;
            break;
        case 3:
            logFile << "Fatal - " << __DATE__ << " " << __TIME__ << " | "  << message << std::endl;
            break;
        default:
            logFile << __DATE__ << " " << __TIME__ << " | " << message << std::endl;
            break;
        }            
}

bool Logger::close()
{
    logFile.close();
	return (true);
}