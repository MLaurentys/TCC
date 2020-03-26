#include "../include/dom_evaluator.h"

using std::make_tuple;
using std::tuple;

bool test1(){
    Domineering d(3,2);
    DomEvaluator de;
    d.make_move(make_tuple(make_tuple(0, 1), make_tuple(1, 1)));
    d.print_board();
    //de.evaluate(d);
    return false;
}

int main(){
    std::cout << "test 1:\n" << test1() << "\n";
    return 0;
}