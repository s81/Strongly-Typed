#include "headers.hpp"

auto main() -> int
{
    auto numbers = std::views::iota(0) | std::views::take(30'000);

    auto evens = 
        numbers | std::views::transform([](auto number) { return (number << 1); })
                | std::views::for_each([](auto number) { std::cout << number << ' '; });
    std::cout << '\n';
    auto odds =
        numbers | std::views::transform([](auto number) { return (number << 1) + 1; })
                | std::views::for_each([](auto number) { std::cout << number << ' '; });

}