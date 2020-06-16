#include <memory>

#include "../include/dom_evaluator.hpp"
//#include "../../game_numbers/include/game_number_repr.hpp"

using std::make_tuple;
using std::tuple;
using std::cout;
using std::endl;

using gn_ptr = std::unique_ptr<GameNumber>;
using sets = GameNumberS<GNRepresentation::sets>;
using real = GameNumberS<GNRepresentation::real>;

// bool test0() {
//     gn_ptr gn = std::make_unique<real> (10.0f);
//     gn_ptr gn2 = std::make_unique<real> (11.0f);
//     cout << (gn == gn2) << endl;
//     cout << (gn != gn2) << endl;
//     cout << (gn < gn2) << endl;
//     cout << (gn <= gn2) << endl;
//     cout << (gn > gn2) << endl;
//     cout << (gn >= gn2) << endl;
// }

bool test1(){
    Domineering d(2,3);
    DomEvaluator de;
    d.make_move({{0,1}, {1,1}});
    d.print_board();
    std::vector<game> evaluation = de.evaluate(d);
    int sz = static_cast<int>(evaluation.size());
    for (int i = 0; i < sz - 1; ++i) {
        de.print_evaluation(evaluation[i]);
        cout << " + ";
    }
    if (sz) de.print_evaluation(evaluation[sz-1]);
    cout << "\n";
    for (auto& e : evaluation) {
        std::shared_ptr<GameNumber> gn =
            std::make_shared<GameNumberS<GNRepresentation::sets>>(
            e,
            gameF::get_eval,
            gameF::lIter,
            gameF::rIter);
        bool is_sur = gn->is_surreal();
        cout << "Is surreal? ";
        if (is_sur)
            cout <<  "Yes -> " << "Value = " << gn->get_float();
        else
            cout << "No";
        cout << "\n";
    }
    return false;
}

bool test2(){
    Domineering d(2,3);
    DomEvaluator de;
    d.make_move({{0,1}, {0,2}});
    d.print_board();
    auto evaluation = de.evaluate(d);
    int sz = static_cast<int>(evaluation.size());
    for (int i = 0; i < sz - 1; ++i) {
        de.print_evaluation(evaluation[i]);
        cout << " + ";
    }
    if (sz) de.print_evaluation(evaluation[sz-1]);
    cout << "\n";
    for (auto& e : evaluation) {
        std::shared_ptr<GameNumber> gn =
            std::make_shared<GameNumberS<GNRepresentation::sets>>(
            e,
            gameF::get_eval,
            gameF::lIter,
            gameF::rIter);
        bool is_sur = gn->is_surreal();
        cout << "Is surreal? ";
        if (is_sur)
            cout <<  "Yes -> " << "Value = " << gn->get_float();
        else
            cout << "No";
        cout << "\n";
    }
    return false;
}

int main(){
    std::cout << "test 0:\n";
    //test0();
    std::cout << "test 1:\n";
    //test1();
    cout << "\n";
    std::cout << "test 2:\n";
    test2();
    cout << "\n";
    return 0;
}