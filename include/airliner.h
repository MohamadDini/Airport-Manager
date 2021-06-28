#include "../include/plane.h"
#ifndef AIRLINER_IG
#define AIRLINER_IG

class airliner :public plane
{
public:
    airliner(std::string,size_t) ;
    void set_notr(size_t);
    size_t get_notr() const ;
    virtual void print_info() const override ;

private:
    size_t notr   ;// number of traveller 
};
#endif // !AIRLINER_IG
