#include <iostream>
#include <string>

struct Musician;

struct Guitarist;

struct Pianist;

struct Violist;

struct Drummerist;

struct Saxsaphoneist;

struct Trumperist;

struct Clarnist;

struct Fluteist;

struct Accordionist;



struct MTI {

    std::string Typename;

    std::string Base_Types;

} mti;



struct GIT {

    std::string Typename;

    std::string Base_Types;

} git;



struct PIT {

    std::string Typename;

    std::string Base_Types;

} pit;



struct VIT {

    std::string Typename;

    std::string Base_Types;

} vit;



struct DIT {

    std::string Typename;

    std::string Base_Types;

} dit;



struct SIT {

    std::string Typename;

    std::string Base_Types;

} sit;



struct TIT {

    std::string Typename;

    std::string Base_Types;

} tit;



struct CIT {

    std::string Typename;

    std::string Base_Types;

} cit;



struct FIT {

    std::string Typename;

    std::string Base_Types;

} fit;



struct AIT {

    std::string Typename;

    std::string Base_Types;

} ait;





struct MVTBL {

    MTI* type_info = &mti;

    void (*play)() = &Musician::play;

} mvtbl;



struct GVTBL {

    GIT* type_info = &git;

    void (*play)() = &Guitarist::play;

} gvtbl;



struct PVTBL {

    PIT* type_info = &pit;

    void (*play)() = &Pianist::play;

} pvtbl;



struct DVTBL {

    DIT* type_info = &dit;

    void (*play)() = &Drummerist::play;

} dvtbl;



struct SVTBL {

    SIT* type_info = &sit; 

    void (*play)() = &Saxsaphoneist::play;

} svtbl;



struct TVTBL {

    TIT* type_info = &tit;

    void (*play)() = &Trumperist::play;

} tvtbl;



struct CVTBL {

    CIT* type_info = &cit;

    void (*play)() = &Clarnist::play;

} cvtbl;



struct FVTBL {

    FIT* type_info = &fit;

    void (*play)() = &Fluteist::play;

} fvtbl;



struct AVTBL {

    AIT* type_info = &ait;

    void (*play)() = &Accordionist::play;

} avtbl;



struct VVTBL {

    VIT* type_info = &vit; 

    void (*play)() = &Violist::play;

} vvtbl;

struct Musician {
   
    static void play() {
        std::cout << "Musician is playing " << std::endl;
    }
    MVTBL* vptr = &mvtbl;
};

struct Guitarist : Musician {
   
    static void play() {
        std::cout << "Guitarist is playing " << std::endl;
    }
    GVTBL* vptr = &gvtbl;
};



struct Pianist : Musician {
   
    static void play() {
        std::cout << "Pianist is playing " << std::endl;
    }
    PVTBL* vptr = &pvtbl;
};

struct Drummerist : Musician {
   
    static void play() {
        std::cout << "Drummerist is playing " << std::endl;
    }
    DVTBL* vptr = &dvtbl;
};

struct Saxsaphoneist : Musician {
   
    static void play() {
        std::cout << "Saxsaphoneist is playing " << std::endl;
    }
    SVTBL* vptr = &svtbl;
};

struct Trumperist : Musician {
   
    static void play() {
        std::cout << "Trumperist is playing " << std::endl;
    }
    TVTBL* vptr = &tvtbl;
};

struct Clarnist : Musician {

    static void play() {
        std::cout << "Clarnist is playing " << std::endl;
    }
    CVTBL* vptr = &cvtbl;

};

struct Fluteist : Musician {
   
    static void play() {
        std::cout << "Fluteist is playing " << std::endl;
    }
    FVTBL* vptr = &fvtbl;
};

struct Accordionist : Musician {

    static void play() {
        std::cout << "Accordionist is playing " << std::endl;
    }
    AVTBL* vptr = &avtbl;
};

struct Violist : Musician {
    static void play() {
        std::cout << "Violist is playing " << std::endl;
    }
    VVTBL* vptr = &vvtbl;

};

namespace {
    template<typename T, typename U>

    T* Dynamic_cast(U* ptr) {
        if (ptr->vptr->type_info->Typename == typeid(T).name()) {

            return static_cast<T*>(ptr);

        }
        if (ptr->vptr->type_info->Base_Types == typeid(T).name()) {

            return static_cast<T*>(ptr);

        }
        return nullptr;

    }
};