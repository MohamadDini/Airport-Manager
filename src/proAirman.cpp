#include "../include/pro_airman.h"
#include <iostream>
proAirman::proAirman(std::string name, std::string id,size_t age,size_t degree):airman(name,id,age)
{
    set_degree(degree) ;
}
void proAirman::set_degree(size_t d)
{
    degree=d ;
} 
size_t proAirman::get_degree() const
{
    return degree ;
}
void proAirman::print_report() const 
{
    airman::print_report() ;
    std::cout<<"airman property (degree)==> "<<"\t"<<get_degree()<<std::endl;
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;

}
