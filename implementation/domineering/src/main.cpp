#include <memory>

#include "../include/dom_evaluator.hpp"
#include "../../game_numbers/include/game_number_repr.hpp"

using std::make_tuple;
using std::tuple;
using std::cout;
using std::endl;

using gn_ptr = std::unique_ptr<GameNumber>;

std::unique_ptr<GameNumberS<GNRepresentation::real>> (*mk_gns_ptr)(float) =
    std::make_unique<GameNumberS<GNRepresentation::real>>;

bool test0() {
    gn_ptr gn = std::make_unique<GameNumberS<GNRepresentation::real>> (10.0f);
    gn_ptr gn2 = mk_gnr_ptr (11.0f);
    cout << (gn == gn2) << endl;
    cout << (gn != gn2) << endl;
    cout << (gn < gn2) << endl;
    cout << (gn <= gn2) << endl;
    cout << (gn > gn2) << endl;
    cout << (gn >= gn2) << endl;
}

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
    std::cout << "test 0:\n";
    test0();
    std::cout << "test 1:\n";
    test1();
    cout << "\n";
    std::cout << "test 2:\n";
    test2();
    cout << "\n";
    return 0;
}