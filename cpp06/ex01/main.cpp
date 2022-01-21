#include <iomanip>
#include <iostream>

#include "Data.hpp"

Data *deserialize(const uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

uintptr_t serialize(const Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

int main() {
    {
        Data data = {
            42,
            "hogeee",
        };
        std::cout << "&data   : " << &data << std::endl;
        std::cout << "data num   : " << data.num << std::endl;
        std::cout << "data str   : " << data.str << std::endl;

        std::cout << "- serialize -" << std::endl;
        uintptr_t raw = serialize(&data);

        std::cout << "- deserialize -" << std::endl;
        Data *deserial = deserialize(raw);
        std::cout << "deserial: " << deserial << std::endl;
        std::cout << "deserial num   : " << deserial->num << std::endl;
        std::cout << "deserial str   : " << deserial->str << std::endl;
    }

    {
        std::cout << "\n-- const test --" << std::endl;
        const Data data = {
            42,
            "hogeee",
        };
        std::cout << "&data   : " << &data << std::endl;
        std::cout << "data num   : " << data.num << std::endl;
        std::cout << "data str   : " << data.str << std::endl;

        std::cout << "- serialize -" << std::endl;
        const uintptr_t raw = serialize(&data);

        std::cout << "- deserialize -" << std::endl;
        Data *deserial = deserialize(raw);
        std::cout << "deserial: " << deserial << std::endl;
        std::cout << "deserial num   : " << deserial->num << std::endl;
        std::cout << "deserial str   : " << deserial->str << std::endl;
    }
}

/*
int main() {
    {
        Data data = {
            42,
            "hogeee",
        };
        std::cout << "&data   : " << &data << std::endl;
        std::cout << "data num   : " << data.num << std::endl;
        std::cout << "data str   : " << data.str << std::endl;

        uintptr_t raw = serialize(&data);
        std::cout << "raw     : " << std::hex << std::showbase << raw
                  << std::endl;

        Data *deserial = deserialize(raw);
        std::cout << "deserial: " << std::hex << std::showbase << deserial
                  << std::endl;
        std::cout << "deserial num   : "
                  << std::resetiosflags(std::ios::showbase)
                  << std::resetiosflags(std::ios::hex) << deserial->num
                  << std::endl;
        std::cout << "deserial str   : " << deserial->str << std::endl;
    }
    {
        std::cout << "\n-- const test --" << std::endl;
        const Data data = {
            42,
            "hogeee",
        };
        std::cout << "&data   : " << &data << std::endl;
        std::cout << "data num   : " << data.num << std::endl;
        std::cout << "data str   : " << data.str << std::endl;

        const uintptr_t raw = serialize(&data);
        std::cout << "raw     : " << std::hex << std::showbase << raw
                  << std::endl;

        Data *deserial = deserialize(raw);
        std::cout << "deserial: " << std::hex << std::showbase << deserial
                  << std::endl;
        std::cout << "deserial num   : "
                  << std::resetiosflags(std::ios::showbase)
                  << std::resetiosflags(std::ios::hex) << deserial->num
                  << std::endl;
        std::cout << "deserial str   : " << deserial->str << std::endl;
    }
}
*/
