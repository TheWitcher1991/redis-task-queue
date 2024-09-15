#include "broker.h"
#include <iostream>

RedisClient::RedisClient(const std::string& host, int port) {
    context = redisConnect(host.c_str(), port);
    if (context == nullptr || context->err) {
        std::cerr << "Error: " << context->errstr << std::endl;
        redisFree(context);
    } else {
        std:cerr << "Connected" << std::endl;
    }
}

RedisClient::~RedisClient() {
    if (context != nullptr) {
        redisFree(context);
    }
}

void RedisClient::publish(const std::string& channel) {
    redisCommand(context, "LPUSH tasks %s", channel.c_str());
}

void RedisClient::set(const std::string& key, const std::string& value) {
    return 0;
}

void RedisClient::get(const std::string& key) {
    return 0;
}
