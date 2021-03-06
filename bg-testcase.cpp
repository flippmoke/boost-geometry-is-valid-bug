#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>
#include <boost/geometry/algorithms/is_valid.hpp>

/*

clang++ -o bg bg-testcase.cpp -Imason_packages/.link/include/ -std=c++11 -O0 -DDEBUG;./bg

*/

int main()
{
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<std::int64_t>, true > polygon;
    typedef boost::geometry::model::multi_polygon<polygon> multi_polygon;

    // multi_polygon
    multi_polygon valid_polygon;
    boost::geometry::read_wkt("MULTIPOLYGON (((15 17, 12 23, 15 20, 15 17)), ((35 23, 34 23, 34 24, 35 25, 36 25, 35 23)), ((8 6, 7 24, 10 25, 12 25, 12 23, 11 23, 10 13, 15 15, 8 6)), ((12 27, 8 31, 6 32, 6 38, 13 34, 13 31, 11 31, 12 30, 11 30, 12 29, 12 27)), ((7 24, 7 26, 6 31, 9 26, 7 24)), ((18 44, 15 45, 15 48, 18 44)), ((26 34, 18 44, 38 39, 26 34)), ((15 33, 13 34, 15 45, 15 33)), ((15 32, 15 33, 17 32, 15 32)), ((19 30, 17 32, 18 32, 16 38, 21 31, 19 30)), ((15 29, 13 30, 13 31, 15 32, 15 29)), ((15 28, 15 29, 17 29, 15 28)), ((14 27, 12 29, 13 30, 15 28, 14 27)), ((30 24, 25 24, 24 26, 25 27, 24 27, 23 28, 19 28, 19 29, 17 29, 18 30, 19 30, 22 29, 21 31, 26 34, 31 27, 28 30, 26 27, 30 24)), ((15 26, 15 28, 17 26, 15 26)), ((27 27, 31 27, 34 27, 32 26, 27 27)), ((19 25, 17 26, 19 26, 19 25)), ((41 15, 33 18, 35 23, 41 15)), ((23 24, 20 25, 19 26, 24 27, 24 26, 23 24)), ((33 15, 46 5, 48 4, 49 1, 32 13, 33 15)), ((32 23, 31 24, 32 25, 32 26, 33 25, 32 23)), ((35 23, 43 23, 44 23, 44 22, 43 22, 42 15, 35 23)), ((43 23, 36 25, 38 31, 35 25, 33 25, 34 27, 39 34, 40 39, 38 39, 44 42, 43 23)), ((48 22, 44 23, 48 46, 48 22)), ((18 11, 23 2, 15 3, 18 11)), ((29 17, 26 20, 22 23, 23 24, 25 24, 27 21, 28 20, 30 19, 29 17)), ((22 19, 21 20, 21 21, 24 19, 22 19)), ((31 23, 34 23, 31 19, 30 19, 31 22, 27 21, 30 24, 31 24, 31 23)), ((21 18, 20 21, 21 20, 21 18)), ((14 27, 15 26, 16 25, 19 25, 20 24, 22 23, 21 21, 20 21, 17 17, 15 20, 15 25, 12 25, 12 26, 14 26, 14 27), (20 21, 20 22, 17 24, 20 21)), ((22 17, 22 19, 23 18, 22 17)), ((30 15, 32 13, 31 10, 28 13, 30 15)), ((16 16, 17 17, 18 17, 16 16)), ((15 15, 15 17, 16 16, 15 15)), ((30 15, 29 16, 29 17, 30 17, 30 15)), ((33 15, 30 17, 31 19, 33 18, 33 15)), ((43 14, 44 22, 48 22, 48 4, 47 7, 42 13, 43 14)), ((43 14, 42 14, 41 15, 42 15, 43 14)), ((27 10, 25 6, 23 13, 27 11, 49 1, 24 2, 27 10)), ((28 13, 23 18, 24 19, 29 16, 28 13)), ((15 11, 15 15, 16 15, 17 13, 15 11)), ((18 11, 17 13, 19 15, 18 17, 21 18, 21 17, 20 15, 22 17, 23 13, 20 14, 18 11)), ((8 6, 8 5, 15 11, 15 3, 5 3, 8 6)))"
        , valid_polygon);

    // Validate the polygon
    {
        std::string reason;
        if (!boost::geometry::is_valid(valid_polygon, reason))
        {
            std::clog << "Not valid - reason: " << std::endl;
            std::clog << reason << std::endl;
        }
        else
        {
            std::clog << "Polygon is valid" << std::endl;
        }
    }

    return 0;
}
