#include <iostream>

struct DTI;
struct STI;
struct RTI;
struct HTI;

class Musician {
public:
    static void play(){
        std::cout << "Musician";
    }
};

class Drummer : public Musician {
public:
   static void play() {
        std::cout << "Drummer is playing" << std::endl; 
   }
};

struct DVTBL  {
    void (*play)() = Drummer::play;
    DTI* dti = dti;
};

struct DTI  {
  const char* Typename = "Drummer";
  const char* Base_Type = "Musician";
}dti;

namespace Drum {
   Musician* play(){
   Drummer* p;
   p->play();
   return nullptr;
}
}

class Singer : public Musician {
public:
    static void play() {
        std::cout << "Singer is playing " << std::endl; 
    }
};

struct SVTBL {
    void (*play)() = Singer::play;
    STI* sti = sti;
};

struct STI {
    const char* Typename = "Singer";
    const char* Base_Type = "Musician";
}sti;

namespace Sing {
    Musician* play() {
    Singer* p;
    p->play();
    return nullptr;
}
}

class Rocker : public Musician {
public:   
    static void play() {
        std::cout << "Rocker is playing " << std::endl; 
    }
};

struct RVTBL {
    void (*play)() = Rocker::play;
    RTI* rti = rti; 
};

struct RTI {
    const char* Typename = "Rocker";
    const char* Base_Type = "Musician";
}rti;

namespace Rock {
    Musician* play() {
    Rocker* ob; 
    ob->play();
    return nullptr;
}
}

class HipHop : public Musician {
public:
    static void play() {
        std::cout << "HipHop is playing " << std::endl; 
    }
};

struct HVTBL {
    void (*play)() = HipHop::play;
    HTI* hti = hti; 
};

struct HTI {
    const char* Typename = "HipHop";
    const char* Base_Type = "Musician";
}hti;

namespace Hip {
    Musician* play(){
    HipHop* ob; 
    ob->play();
    return nullptr;
}
}