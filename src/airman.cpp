#include "../include/airman.h"
#include <iostream>


airman::airman(std::string name, std::string id,size_t age)
{
    set_name(name) ;
    set_age(age) ;
    set_id(id) ;
} 
void airman::set_name(std::string s)
{
    name=s ;
}
void airman::set_id(std::string i) 
{
    id=i ;
}
void airman::set_age(size_t age)
{
    this->age=age ;
}
size_t airman::get_age() const
{
    return age ;
}
std::string airman::get_id() const 
{
    return id ;
}
std::string airman::get_name() const 
{
    return name ;
}
void airman::print_report() const 
{
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;
    std::cout<<"airman name==> "<<"\t"<<get_name()<<std::endl;
    std::cout<<"airman id==> "<<"\t"<<get_id()<<std::endl;
    std::cout<<"airman age==> "<<"\t"<<get_age()<<std::endl;
}
void airman::set_busy(bool bol) 
{
    busy=bol ;
}
bool airman::get_busy() const 
{
    return busy ;
}