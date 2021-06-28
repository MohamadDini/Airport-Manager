#ifndef FLYING_IG
#define FLYING_IG
#include <string>
class flying
{
public:
    flying(std::string ,std::string , std::string ,std::string) ;
    //flying() ;
    void set_id() ;
    size_t get_id() const ;
    void print_report() const ;

    std::string get_id_plane() const ;
    std::string get_id_airman() const ;
    //bool add_fly(std::string ,std::string , std::string ,std::string) ;
    //bool delete_fly()
private:
    std::string origin ;
    std::string goal ;
    std::string id_airman ;
    std::string id_plane ;
    //size_t date;
    size_t id_fly ;
};

#endif // !FLYING_IG
