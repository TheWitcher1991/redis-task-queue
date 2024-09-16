#include "config.h"
#include "include/redis/client.h"

int main() {
    config Config();

    redis RedisClient(config::redisHost, config::redisPort, config::redisPassword, config::redisDB);

    return 0;
}
