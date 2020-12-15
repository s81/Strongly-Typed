#include <iostream>
#include <ratio>

template <typename named_type, typename tag_type, typename ratio>
struct unit{
    explicit unit(named_type value_) 
        :value(std::move(value_)) {}; 
    named_type value{};
};

using cent = unit<uint32_t, struct cent_, std::ratio<1>>;
using decimal = long double;
using dollar = unit<double, struct dollar_, std::ratio<100,1>>;


cent   operator "" _cents(uint64_t value_) { return cent(value_); }
dollar operator"" _dollars(decimal value_) { return dollar(value_); }
dollar operator+ (dollar ds, cent cs) { return dollar(ds.value + (0.01 * cs.value));}
dollar operator= (cent cs) { return dollar(0.01 * cs.value);}

int main()
{

    cent other_cash = 4000_cents;
    dollar my_cash = 406.76_dollars;

    std::cout << my_cash.value <<" dollars\n";
    std::cout << other_cash.value <<" cents\n";
    std::cout << (my_cash + other_cash).value << " dollars\n";

    my_cash = 400_cents;

    std::cout << my_cash.value <<" dollars\n";



}