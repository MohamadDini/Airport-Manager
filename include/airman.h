#ifndef AIRMAN_IG
#define AIRMAN_IG
#include <string>
#include <vector>
class airman
{
public:
    airman(std::string , std::string ,size_t) ;
    void set_name(std::string) ;
    void set_id(std::string) ;
    void set_age(size_t) ;
    size_t get_age() const ;
    std::string get_id() const ;
    std::string get_name() const ;
    virtual void print_report() const ;
    void set_busy(bool) ;
    bool get_busy() const ;
private:
    std::string name ;
    std::string id ;
    size_t age ;
    bool busy=false ;

};
#endif // !AIRMAN_IG
