#include "include/redis/client.h"
#include <iostream>

RedisClient::RedisClient(const std::string& host, int port, const std::string& password, int db) {
    context = redisConnect(host.c_str(), port, password.c_str(), db);
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

void RedisClient::publish(const std::string& channel, const std::string& message) {
    redisCommand(context, "PUBLISH %s %s", channel.c_str(), message.c_str());
}

void RedisClient::set(const std::string& key, const std::string& value) {
    redisCommand(context, "SET %s %s", key.c_str(), value.c_str());
}

void RedisClient::get(const std::string& key) {
    redisCommand(context, "GET %s", key.c_str());
}

void RedisClient::del(const std::string& key) {
    redisCommand(context, "DEL %s", key.c_str());
}

void RedisClient::pop(const std::string& key) {
    redisReply *reply = (redisReply*)redisCommand(context, "RPOP %s", key.c_str();
    if (reply->type == REDIS_REPLY_STRING) {
        std::string task = reply->str;
        freeReplyObject(reply);
        return task;
    }
    freeReplyObject(reply);
    return "";
}
