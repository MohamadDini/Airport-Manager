#include "../include/plane.h"
#ifndef CARGO_IG
#define CARGO_IG

class cargo :public plane
{
public:
    cargo(std::string,float) ;
    void set_weight_pro(float) ;
    float get_weight_pro() const ;
    virtual void print_info() const override ;
private:
    float weight_pro ;
};
#endif