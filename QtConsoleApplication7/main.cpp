#include <QtCore/QCoreApplication>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <qdebug.h>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point2;
typedef Kernel::Triangle_2 Triangle2;
typedef Kernel::Segment_2 Segment2;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Point2 p1(-5, 0);
    Point2 p2(5, 0);
    Point2 p3(0, 5);

    Point2 p4(-3,0);
    Point2 p5(3, 0);
    Point2 p6(0, 5);



    Triangle2 t1(p1, p2, p3);
    Triangle2 t2(p4, p5, p6);

    if (!CGAL::do_intersect(t1, t2)) {

        qInfo() << "Trójk¹ty siê nie przecinaj¹!";
    }

    else {

        CGAL::Object result = CGAL::intersection(t1, t2);
            Point2 point;
            Segment2 segment;
            Triangle2 triangle;
            std::vector<Point2> polypoint;
    
            if (CGAL::assign(point, result)) { std::cout << "to punkt!"; }
            else
                if (CGAL::assign(segment, result)) { std::cout << "to odcinek!"; }
                else 
                    if (CGAL::assign(triangle, result)) { std::cout << "to trójk¹t!"; } //true
                    else
                        if (CGAL::assign(polypoint, result)) { std::cout << "to wielok¹t!"; }
                        else { std::cout << "unknown!"; }
    }
    return a.exec();
}
