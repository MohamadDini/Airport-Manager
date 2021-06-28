#ifndef PLANE_IG
#define PLANE_IG
#include <string>
#include <vector>

class plane
{
public:
    plane(std::string) ;
    void set_id(std::string) ;
    std::string get_id() const ;
    virtual void print_info() const ;    
    void set_busy(bool) ;
    bool get_busy() const ; 
private:
    std::string id_plane ;
    bool busy=false ;
};

#endif 