#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <map>
#include <cassert>
// #include<stdio.h>

class table_manager;

class RegisterManager {
private:
    std::map<int, table_manager *> list;

    RegisterManager() = default;

    ~RegisterManager() = default;

public:
    RegisterManager(RegisterManager const &) = delete;

    RegisterManager &operator=(RegisterManager const &) = delete;

    static RegisterManager &get_instance() {
        static RegisterManager instance;
        return instance;
    }

    void checkIn(int permID, table_manager *table_manager) {
        // printf("\n%d %d\n",list.find(permID),list.end());
        assert(list.find(permID) == list.end());
        list[permID] = table_manager;
    }

    table_manager *getPtr(int permID) {
        assert(list.find(permID) != list.end());
        return list[permID];
    }

    void checkOut(int permID) {
        list.erase(permID);
    }
};


#endif
