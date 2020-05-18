#include "../include/dom_evaluator.h"

using std::make_tuple;
using std::tuple;
using std::cout;

bool test1(){
    Domineering d(2,3);
    DomEvaluator de;
    d.make_move({{0,1}, {1,1}});
    d.print_board();
    auto evaluation = de.evaluate(d);
    for (auto& e : evaluation) {
        de.print_evaluation(e);
        cout << " + ";
    }
    
    return false;
}

bool test2(){
    Domineering d(2,3);
    DomEvaluator de;
    d.make_move({{0,1}, {0,2}});
    d.print_board();
    auto evaluation = de.evaluate(d);
    for (auto& e : evaluation) {
        de.print_evaluation(e);
        cout << " + ";
    }
    
    return false;
}

int main(){
    std::cout << "test 1:\n";
    test1();
    cout << "\n";
    std::cout << "test 2:\n";
    test2();
    cout << "\n";
    return 0;
}