#include "../include/airman.h"
#ifndef BEG_AIRMAN_IG
#define BEG_AIRMAN_IG

class begAirman:public airman
{
public:
    begAirman(std::string , std::string ,size_t,size_t) ;
    void set_nof(size_t) ;
    size_t get_nof() const ;
    virtual void print_report() const ;
private:
    size_t nof ; // nof == number of flying ...
};

#endif