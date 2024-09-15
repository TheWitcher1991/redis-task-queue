#ifndef REDIS_CLIENT_H
#define REDIS_CLIENT_H

##include <string>
#include <hiredis/hiredis.h>

class RedisClient {
private:
    redisContext *context;

public:
    RedisClient(const std::string &host, int port);
    ~RedisClient();

    void publish(const std::string &channel);
    std::string set(const std::string &key, const std::string &value);
    std::string get(const std::string &key);
}

#endif // REDIS_CLIENT_H