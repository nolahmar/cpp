#ifndef __TEST__HPP
#define __TEST__HPP

class ITest {
    public:
    virtual void print_hello() const = 0;
};


class Test : public ITest {
    public:
    void print_hello() const;
};

#endif