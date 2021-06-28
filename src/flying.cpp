#include "../include/flying.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
flying::flying(std::string origin,std::string goal, std::string id_airman,std::string id_plane)
{
    this->origin=origin ;
    this->goal=goal ;
    this->id_airman=id_airman ;
    this->id_plane=id_plane ;
    this->set_id() ;
}
void flying::set_id() 
{
    srand(time(0)) ;
    id_fly=rand()%10 ;
}
size_t flying::get_id() const 
{
    return id_fly ;
}
std::string flying::get_id_plane() const 
{
    return id_plane ;
}
std::string flying::get_id_airman() const 
{
    return id_airman ;
}
void flying::print_report() const 
{
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;
    std::cout<<"flying from==> "<<"\t"<<origin<<std::endl;
    std::cout<<"flying to==> "<<"\t"<<goal<<std::endl;
    std::cout<<"fly management by id_airman==> "<<"\t"<<id_airman<<std::endl;
    std::cout<<"fly by id_plane==> "<<"\t"<<id_plane<<std::endl;
    std::cout<<"fly by id_fly==> "<<"\t"<<get_id()<<std::endl;
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;
}
