#ifndef Converter_HPP
#define Converter_HPP

#include <string>

enum e_type { CHAR, INT, FLOAT, DOUBLE };

class Converter {
public:
    Converter();
    Converter(std::string str);
    virtual ~Converter();
    Converter(Converter const &other);
    Converter &operator=(Converter const &other);
    int init();
    e_type getType() const;
    void printConverted();

private:
    void detectType();
    void acquireChar();
    int acquireInt();
    int acquireFloat();
    int acquireDouble();
    void intCase(std::string const type[]);
    void floatCase(std::string const type[]);
    void doubleCase(std::string const type[]);

    std::string _str;
    bool _special;
    e_type _type;
    char _c;
    int _i;
    float _f;
    double _d;
};

#endif
