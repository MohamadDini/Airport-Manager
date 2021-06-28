#include <iostream>
#include <vector>
#include "../include/pro_airman.h"
#include "../include/beg_airman.h"
#include "../include/flying.h"
#include "../include/cargo.h"
#include "../include/airliner.h"
#include <typeinfo>
using namespace std ;

int main()
{
    vector<airman *>vec1{nullptr} ;
    vector<flying *> vec2{nullptr};
    vector<plane *> vec3{nullptr} ;
    cout<<"==>> wellcome to management airport!!!"<<endl;
    size_t sel_out, sel_in ;
    cout<<"==>> which one is you want ?\n(1_add plane \t 2_add airman \t 3_add flying \t 4_delete plane    5_delete airman \t6_delete flying \t7_reporting)"<<endl;
    cin>>sel_out ;
    do
    {
        try
        {
            switch (sel_out)
            {
                case 1:
                {
                    int count=0 ;
                    for(int i=0;i<vec3.size();i++)
                    {
                        if(vec3[i]!=nullptr)
                            count++ ;
                    }
                    if(count==20)
                        throw out_of_range("capacity of the planes is full!!!") ;
                    cout<<"which one is should add? (1_airlinerPlane \t 2_cargoPlane)"<<endl;
                    cin>>sel_in ;
                    cout<<"enter name of id_plane:\t tips(for airliner=='ar..' & for cargo=='cr..')"<<endl;
                    string strid ;
                    cin>>strid;                    
                    cin.ignore() ;
                    for(int i=0;i<vec3.size();i++)
                    {
                        if(vec3[i]!=nullptr && vec3[i]->get_id()==strid)
                        {
                            cout<<"id_plane is duplicate!!!"<<endl;
                            cout<<"enter name of id_plane:"<<endl;
                            getline(cin,strid) ;
                        }
                    }
                    if(sel_in==1)
                    {
                        cout<<"enter the traveler capacity:"<<endl;
                        size_t num ;
                        cin>>num ;
                        vec3.push_back(new airliner(strid,num)) ;
                    }
                    else if(sel_in==2)
                    {
                        cout<<"enter the weight capacity:"<<endl;
                        float num ;
                        cin>>num ;
                        vec3.push_back(new cargo(strid,num)) ;
                    }  
                    break;
                }
                case 2:
                {
                    int count=0 , age ;
                    string name ,airman_id;
                    for(int i=0;i<vec1.size();i++)
                    {
                        if(vec1[i]!=nullptr)
                            count++ ;
                    }
                    if(count==10)
                        throw out_of_range("airmans are 10 person!!!") ;
                    cout<<"enter the name of airman:"<<endl;
                    getchar() ;
                    getline(cin,name) ;
                    cout<<"==>> which one is you want ? \n (1_proAirman \t 2_begAirman "<<endl;
                    cin>>sel_in ;
                    cout<<"enter the airman id:\t tips(for professinals=='pr..' & for beginners=='bg..')"<<endl;
                    cin>>airman_id ;
                    cin.ignore() ;
                    for(int i=0;i<vec1.size();i++)
                    {
                        if(vec1[i]!=nullptr && vec1[i]->get_id()==airman_id)
                        {
                            cout<<"airman_id is duplicate!!!"<<endl;
                            cout<<"enter name of airman_id:"<<endl;
                            cin>>airman_id ;
                        }
                    }
                    cout<<"enter the airmans age:"<<endl;
                    cin>>age ;
                    if(sel_in==1)
                    {
                        size_t degree ;
                        cout<<"enter the airmans degree:\t tips(1 or 2)"<<endl;
                        cin>>degree;
                        vec1.push_back(new proAirman(name, airman_id,age,degree)) ;
                    }
                    if(sel_in==2)
                    {
                        size_t numberOfTravel ;
                        cout<<"enter the number of travel for this airman:"<<endl;
                        cin>>numberOfTravel ;
                        vec1.push_back(new begAirman(name,airman_id,age,numberOfTravel)) ;
                    }
                    break ;
                }
                case 3:
                {
                    int count=0 ;
                    bool flag1=false  ,flag2=false ;
                    string origin , goal, id_airman, id_plane ;
                    for(int i=0;i<vec2.size();i++)
                    {
                        if(vec2[i]!=nullptr)
                            count++ ;
                    }
                    if(count==8)
                        throw out_of_range("the airport has 8 flights today!!!") ;
                    cout<<"enter origin:"<<endl;
                    cin>>origin ;
                    cout<<"enter goal:"<<endl;
                    cin>>goal ;
                    cout<<"enter id_airman:"<<endl;
                    cin>>id_airman ;
                    cout<<"enter id_plane:"<<endl;
                    cin>>id_plane ;
                    for(int i=0;i<vec1.size();i++)
                    {
                        if(vec1[i]!=nullptr && vec1[i]->get_id()==id_airman && vec1[i]->get_busy()==false)
                        {
                            flag1=true ;
                        }
                        // else
                        // {
                        //     flag1=false ;
                        // }      
                    }
                    for(int j=0;j<vec3.size();j++)
                    {
                        if(vec3[j]!=nullptr && vec3[j]->get_id()==id_plane && vec3[j]->get_busy()==false)
                        {
                            flag2=true ;
                        }
                        // else
                        // {
                        //     flag2=false ;
                        // }                  
                    }
                    if(flag1 && flag2)
                    {
                        vec2.push_back(new flying( origin,goal,id_airman,id_plane)) ;
                        cout<<"the flight addition is successfil !!!"<<endl;
                    }
                    else
                    {
                        cout<<"the flight addition is unsuccessful !!!"<<endl;
                    }
                    break ;
                }
                case 4:
                {
                    string str ;
                    cout<<"enter id_plane which must deleted:"<<endl;
                    cin>>str ;
                    for(int i=0;i<vec3.size();i++)
                    {
                        if( vec3.at(i)!=nullptr  && vec3.at(i)->get_id()==str)
                        {
                            delete vec3[i] ;
                            vec3[i]=nullptr ;
                            cout<<"completed!!!"<<endl;
                            break;
                        }
                        if(i==vec1.size()-1)
                            cout<<"not found your airman!!!"<<endl;
                    }
                    break; 
                }
                case 5:
                {
                    string str ;
                    cout<<"enter id_airman who must deleted:"<<endl;
                    cin>>str ;
                    for(int i=0;i<vec1.size();i++)
                    {
                        if( vec1.at(i)!=nullptr && vec1.at(i)->get_id()==str)
                        {
                            delete vec1[i] ;
                            vec1[i]=nullptr ;
                            cout<<"completed!!!"<<endl;
                            break;
                        }
                        if(i==vec1.size()-1)
                            cout<<"not found your airman!!!"<<endl;
                    }
                    break; 
                }
                case 6:
                {
                    size_t id_flying ;
                    cout<<"enter id_flying who must deleted:"<<endl;
                    cin>>id_flying ;
                    for(int i=0;i<vec2.size();i++)
                    {
                        if( vec2.at(i)!=nullptr)
                        {
                            if(vec2.at(i)->get_id()==id_flying)
                            {
                                delete vec2[i] ;
                                vec2[i]=nullptr ;
                                cout<<"complete!!!"<<endl;
                                break;
                            }
                        }
                        if(i==7)
                            cout<<"not found your aflying!!!"<<endl;
                    }
                    break;
                }
                case 7 :
                {
                    cout<<"which do you want to be done ?\n (1_report of all flying daily\t2_report of cargo fly\t3_report of airliner fly\t4_report of professinal airmans\n5_report of beginner airmans\t6_list of planes\t7_list of airmans"<<endl;
                    cin>>sel_in ;
                    bool flag=false ;
                    switch (sel_in)
                    {
                        case 1:
                            {
                                for(int i=0;i<vec2.size();i++)
                                {
                                    if(vec2[i]!=nullptr)
                                    {
                                        vec2[i]->print_report();
                                        flag=true ;
                                    }
                                }
                                if(flag==false)
                                    cout<<"not exist!!!"<<endl;
                                break;
                            }
                        case 2:
                        {
                            size_t place ;
                            for(int i=0;i<vec2.size();i++)
                            {
                                if(vec2[i]!=nullptr)
                                    place=(*(vec2[i])).get_id_plane().find("cr") ;
                                if(place != std::string::npos)
                                {
                                    if(vec2[i]!=nullptr)
                                    {
                                        vec2[i]->print_report();   
                                        flag=true ;
                                    }
                                }
                            }
                            if(flag==false)
                                cout<<"not exist!!!"<<endl;
                            break;
                        }
                        case 3:
                        {
                            size_t place ;
                            for(int i=0;i<vec2.size();i++)
                            {
                                if(vec2[i]!=nullptr)
                                    place=(*(vec2[i])).get_id_plane().find("ar") ;
                                if(place != std::string::npos)
                                {
                                    if(vec2[i]!=nullptr)
                                    {
                                        vec2[i]->print_report();
                                        flag=true ;
                                    }
                                }
                            }
                            if(flag==false)
                                cout<<"not exist!!!"<<endl;
                            break;
                        }
                        case 4:
                        {
                            string str ;
                            for(int i=0;i<vec1.size();i++)
                            {
                                if(vec1[i]!=nullptr)
                                {
                                    str =(string)typeid(*(vec1[i])).name() ;
                                    int place=str.find("pro");
                                    if(place!=std::string::npos)
                                    {
                                        vec1[i]->print_report();
                                        flag=true ;
                                    }
                                }
                            }
                            if(flag==false)
                                cout<<"not exist!!!"<<endl;
                            break ;
                        }
                        case 5:
                        {
                            string str ;
                            for(int i=0;i<vec1.size();i++)
                            {
                                if(vec1[i]!=nullptr)
                                {
                                    str =(string)typeid(*(vec1[i])).name() ;
                                    int place=str.find("beg");
                                    if(place!=std::string::npos)
                                    {
                                        vec1[i]->print_report();
                                        flag=true ;
                                    }
                                }
                            }
                            if(flag==false)
                                cout<<"not exist!!!"<<endl;
                            break ;
                        }  
                        case 6:
                        {
                            for(int i=0;i<vec3.size();i++)
                            {
                                if(vec3[i]!=nullptr)
                                {
                                    vec3.at(i)->print_info() ;
                                }
                            }
                            break ;
                        }
                        case 7:
                        {
                            for(int i=0;i<vec1.size();i++)
                            {
                                if(vec1[i]!=nullptr)
                                {
                                    vec1.at(i)->print_report();
                                }
                            }
                            break ;
                        }
                    }
                    break ;
                }
                getchar() ;
            }
        }
        catch(out_of_range &m)
        {
            cout<<m.what()<<endl; 
        }
        // catch(...)
        // {
        //     cout<<"eception"<<endl;
        // }
        cout<<"==>> which one is you want ?\n(1_add plane \t 2_add airman \t 3_add flying \t 4_delete plane    5_delete airman \t6_delete flying \t7_reporting)"<<endl;
        cin>>sel_out ;
    } while (sel_out!=0);
    for(int j=0;j<vec3.size();j++)
    {
        delete vec1[j] ;
        delete vec2[j] ;
        delete vec3[j] ;
    }
    return 0 ;
}