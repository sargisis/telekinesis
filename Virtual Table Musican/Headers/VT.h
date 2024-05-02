#include <iostream>
#include <string>

struct Musician; 
struct Guitarist; 
struct Pianist;
struct Drummerist;
struct Saxsaphoneist;
struct Trumperist;
struct Clarnist;
struct Fluteist;
struct Accordionist;
struct Violist; 


struct MTI {
    std::string Typename = "Musician";
    std::string Base_Type = "";
} mti;

struct MVTBL {
    MTI* type_info = &mti;

    void (Musician::*play)();

} mvtbl;

struct GIT {
    std::string Typename = "Guitarist";
    std::string Base_Type = "Musician";
} git;

struct GVTBL {
    GIT* type_info = &git;

    void (Guitarist::*play)();

} gvtbl;

struct PIT {
    std::string Typename = "Pianist";

    std::string Base_Type = "Musician";
} pit;
struct PVTBL {
    PIT* type_info = &pit;

    void (Pianist::*play)();

} pvtbl;


struct DIT {

    std::string Typename = "Drummerist";

    std::string Base_Type = "Musician";

} dit;

struct DVTBL {
    DIT* type_info = &dit;

    void (Drummerist::*play)();

} dvtbl;



struct SIT {

    std::string Typename = "Saxsaphoneist";

    std::string Base_Type = "Musician";

} sit;
struct SVTBL {
    SIT* type_info = &sit; 

    void (Saxsaphoneist::*play)();

} svtbl;


struct TIT {

    std::string Typename = "Trumperist";
    std::string Base_Type = "Musician";

} tit;

struct TVTBL {
    TIT* type_info = &tit;

    void (Trumperist::*play)();

} tvtbl;

struct CIT {

    std::string Typename = "Clarnist";
    std::string Base_Type = "Musician";

} cit;

struct CVTBL {
    CIT* type_info = &cit;

    void (Clarnist::*play)();

} cvtbl;


struct FIT {

    std::string Typename = "Fluteist";
    std::string Base_Type = "Musician";

} fit;
struct FVTBL {
    FIT* type_info = &fit;

    void (Fluteist::*play)();

} fvtbl;



struct AIT {
    std::string Typename = "Accordionist";
    std::string Base_Type = "Musician";

} ait;

struct AVTBL {
    AIT* type_info = &ait;

    void (Accordionist::*play)();

} avtbl;

struct VIT {
    std::string Typename = "Violist";
    std::string Base_Type = "Musician";
}vit;

struct VVTBL {

    VIT* type_info = &vit; 

    void (Violist::*play)();

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



struct Pianist {
   
    static void play() {
        std::cout << "Pianist is playing " << std::endl;
    }
    PVTBL* vptr = &pvtbl;
};

struct Drummerist {
   
    static void play() {
        std::cout << "Drummerist is playing " << std::endl;
    }
    DVTBL* vptr = &dvtbl;
};

struct Saxsaphoneist  {
   
    static void play() {
        std::cout << "Saxsaphoneist is playing " << std::endl;
    }
    SVTBL* vptr = &svtbl;
};

struct Trumperist  {
   
    static void play() {
        std::cout << "Trumperist is playing " << std::endl;
    }
    TVTBL* vptr = &tvtbl;
};

struct Clarnist {

    static void play() {
        std::cout << "Clarnist is playing " << std::endl;
    }
    CVTBL* vptr = &cvtbl;

};

struct Fluteist {
   
    static void play() {
        std::cout << "Fluteist is playing " << std::endl;
    }
    FVTBL* vptr = &fvtbl;
};

struct Accordionist {

    static void play() {
        std::cout << "Accordionist is playing " << std::endl;
    }
    AVTBL* vptr = &avtbl;
};

struct Violist {
    static void play() {
        std::cout << "Violist is playing " << std::endl;
    }
    VVTBL* vptr = &vvtbl;

};


    template<typename T, typename U>
    T* Dynamic_cast(U* ptr) {
        if (ptr->vptr->type_info->Typename == typeid(T).name()) {
            return reinterpret_cast<T*>(ptr);
        }
        if (ptr->vptr->type_info->Base_Type == typeid(T).name()) {
            return reinterpret_cast<T*>(ptr);
        }
        return nullptr;
    }

void leader(auto* ob){
    ob->play();
}