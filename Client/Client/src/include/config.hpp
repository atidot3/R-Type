#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define PATH_CONFIG "../Client/configuration/config.cnf"

using namespace std;

class Configuration
{
public:
    void Clear();
    bool Load(const string& File);
    bool Contains(const string& key) const;
    bool Get(const string& key, string& value) const;
    bool Get(const string& key, int&    value) const;
	Configuration();
	~Configuration();

private:
    map<string,string> data;
    static string Trim(const string& str);
};
