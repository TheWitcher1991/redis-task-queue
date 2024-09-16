#ifndef REDIS_CLIENT_H
#define REDIS_CLIENT_H

#include <string>
#include <hiredis/hiredis.h>

class RedisClient {
private:
    redisContext *context;

public:
    RedisClient(const std::string &host, int port, const std::string &password, int db);
    ~RedisClient();

    void publish(const std::string &channel, const std::string &message);

    std::string set(const std::string &key, const std::string &value);
    std::string get(const std::string &key);
    std::string del(const std::string &key);

    std::string pushTask(const std::string &task);
    std::string popTask(const std::string &key);
}

#endif // REDIS_CLIENT_H
