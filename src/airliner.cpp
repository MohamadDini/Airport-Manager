#include "../include/airliner.h"
#include <iostream>
airliner::airliner(std::string str ,size_t num):plane(str)
{
    set_notr(num) ;
}
void airliner::set_notr(size_t num)
{
    notr=num ;
}
size_t airliner::get_notr() const 
{
    return notr ;
}
void airliner::print_info() const
{
    plane::print_info() ;
    std::cout<<"number of traveller==>\t"<<notr<<std::endl;
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;

}
