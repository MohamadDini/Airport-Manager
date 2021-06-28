#include "../include/cargo.h"
#include <iostream>
cargo::cargo(std::string str,float w):plane(str)
{
    set_weight_pro(w) ;
}
void cargo::set_weight_pro(float w) 
{
    weight_pro=w ;
}
float cargo::get_weight_pro() const 
{
    return weight_pro ;
}
void cargo::print_info() const
{
    plane::print_info();
    std::cout<<"weight_pro==>\t"<<weight_pro<<std::endl;
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;

}
