#include "catch_amalgamated.hpp"
#include "../adder.h"

TEST_CASE("adder simple tests", "[adder]") // to jest to co mamy modyfikowac i dodawac i liczba dodanych
//plikow zalezna od liczby klas. plik korzysta z biblioteki catch cos tam ktora bede musial zalaczyc
//w tasku tez zmiany - trzeba podac tam adder.cpp
//w laucnchu nie trzeba chyba zmieniac
{

    Adder adder(10.0, 20.0);

    CHECK(adder.get_first_argument() == 10.0);
    CHECK(adder.get_second_argument() == 20.0);
    CHECK(adder.sum() == 30.0);

    SECTION("modifications of first argument only") 
    {
        adder.set_first_argument(15.45);
        CHECK(adder.get_first_argument() == 15.45);
        CHECK(adder.get_second_argument() == 20.0);
        CHECK(adder.sum() == 35.45);
    }

    SECTION("modifications of second argument only") 
    {
        adder.set_second_argument(6.3);
        CHECK(adder.get_first_argument() == 10.0);
        CHECK(adder.get_second_argument() == 6.3);
        CHECK(adder.sum() == 16.3);
    }

    SECTION("modifications of both arguments") 
    {
        adder.set_first_argument(987.23);
        adder.set_second_argument(7.234);
        CHECK(adder.get_first_argument() == 987.23);
        CHECK(adder.get_second_argument() == 7.234);
        CHECK(adder.sum() == 994.464);
    }

    SECTION("negative numbers") 
    {
        adder.set_first_argument(-15);
        adder.set_second_argument(-9);
        CHECK(adder.get_first_argument() == -15.0);
        CHECK(adder.get_second_argument() == -9.0);
        CHECK(adder.sum() == -24.0);
    }

}
