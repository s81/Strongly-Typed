#include "headers.hpp"

auto is_even = [](int const num) -> bool { return num % 2 == 0; };
auto is_odd = [](int const num) -> bool { return !is_even(num); };
auto new_line = []() -> void { std::cout << '\n'; };

auto main() -> int
{
    auto numbers = std::views::iota(0) | std::views::take(30'000);

    for (auto number : numbers)
        if (is_even(number))
            std::cout << number << ' ';

    new_line();

    for (auto number : numbers)
        if (is_odd(number))
            std::cout << number << ' ';

    auto evens = numbers | std::views::transform([](auto number) { return (number << 1); });

    for (auto even : evens)
        std::cout << even << '\n';

    std::vector<int> numbers_{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto even_ : numbers_)
        if (is_even(even_))
            std::cout << even_ << ' ';
}