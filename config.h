#ifdef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    static std::string redisHost;
    static int redisPort;
    static std::string redisPassword;
    static int redisDb;
}