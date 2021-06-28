#include "../include/plane.h"
#include <iostream>


plane::plane(std::string str)
{
    set_id(str) ;
}
void plane::set_id(std::string str)
{
    this->id_plane=str ;
}
std::string plane::get_id() const
{
    return id_plane ;
}
void plane::print_info() const 
{
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;
    std::cout<<"id_plane==>\t"<<id_plane<<std::endl ;
}   
void plane::set_busy(bool bol) 
{
    busy=bol ;
}
bool plane::get_busy() const 
{
    return busy ;
}
