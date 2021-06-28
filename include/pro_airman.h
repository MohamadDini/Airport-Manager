#include "../include/airman.h"

#ifndef PRO_AIRMAN
#define PRO_AIRMAN

class proAirman :public airman
{
public:
    proAirman(std::string , std::string ,size_t,size_t) ;
    void set_degree(size_t) ;
    size_t get_degree() const ;
    virtual void print_report() const ;
private:
    size_t degree ;
};
#endif
