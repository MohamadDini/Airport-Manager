#include "../include/beg_airman.h"
#include <iostream>

begAirman::begAirman(std::string name, std::string id,size_t age,size_t nof):airman(name,id,age)
{
    set_nof(nof) ;
}
void begAirman::set_nof(size_t nof) 
{
    this->nof=nof ;
}
size_t begAirman::get_nof() const
{
    return nof ;
}
void begAirman::print_report() const 
{
    airman::print_report() ;
    std::cout<<"airman property (number of flying)==> "<<"\t"<<get_nof()<<std::endl;
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;

}
