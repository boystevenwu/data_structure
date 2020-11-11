#include "proj3.hpp"
#include "Wordset.hpp"


int main()
{
    WordSet w;

    w.insert("ant");
    w.insert("aot");
    w.insert("aft");
    w.insert("oft");
//    w.print();
//    std::cout << w.getCapacity() << " " << w.getCount() << std::endl;

    w.insert("oot");
    w.insert("oat");
    w.insert("eat");
//    w.print();
//    std::cout << w.getCapacity() << " " << w.getCount() << std::endl;

    std::cout << convert("ant", "eat", w);

    return 0;
}

