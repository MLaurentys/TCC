/*
 * This file is the starting point of my thesis code.
 * You can compile the code with either make or using cmake, although cmake is
 *  prefered.
 * This file runs tests and prints readable output that show how combinatorial
 *  games are represented though numbers and how advantadges is each position
 *  can be calculated.
 */

#include <memory>

#include "../include/dom_evaluator.hpp"
#include "../../game_numbers/include/game_number.hpp"
#include "../../game_numbers/include/game_number_repr.hpp"

using std::vector, std::cout, std::endl;
using gn_ptr = std::unique_ptr<GameNumber>;
using sets = GameNumberS<GNRepresentation::sets>;
using real = GameNumberS<GNRepresentation::real>;

bool test0() {
    gn_ptr gn = std::make_unique<real> (10.0f);
    gn_ptr gn2 = std::make_unique<real> (11.0f);
    cout << (gn == gn2) << endl;
    cout << (gn != gn2) << endl;
    cout << (gn < gn2) << endl;
    cout << (gn <= gn2) << endl;
    cout << (gn > gn2) << endl;
    cout << (gn >= gn2) << endl;
    return false;   
}

bool test1(){
    cout << "hashmap at the beggining:\n";
    for (auto& kv : DomEvaluator::hmap) {kv.first.print();}
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
    cout << "hashmap at the beggining:\n";
    for (auto& kv : DomEvaluator::hmap) {kv.first.print();}
    Domineering d(2,3);
    DomEvaluator de;
    d.make_move({{0,1}, {0,2}});
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
    cout << "hashmap at the end:\n";
    for (auto& kv : DomEvaluator::hmap) {kv.first.print();}

    return false;
}

bool test3(){
    cout << "hashmap at the beggining:\n";
    for (auto& kv : DomEvaluator::hmap) {kv.first.print();}
    Domineering d(5,5);
    DomEvaluator de;
    d.make_move({{0,1}, {0,2}});
    d.make_move({{2,0}, {2,1}});
    d.make_move({{1,2}, {2,2}});
    d.make_move({{3,2}, {4,2}});
    d.make_move({{3,3}, {3,4}});
    //d.make_move({{2,3}, {2,4}});
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
        bool is_sur = false;
        try {
            is_sur = gn->is_surreal();
        }
        catch (const std::exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        cout << "Is surreal? ";
        if (is_sur)
            cout <<  "Yes -> " << "Value = " << gn->get_float();
        else
            cout << "No";
        cout << "\n";
    }
    cout << "hashmap at the end:\n";
    for (auto& kv : DomEvaluator::hmap) {kv.first.print();}
    return false;
}

int main(){
    std::cout << "test 0:\n";
    test0();
    // std::cout << "test 1:\n";
    // test1();
    // cout << "\n";
    // std::cout << "test 2:\n";
    // test2();
    // cout << "\n";
    // std::cout << "test 3:\n";
    // test3();
    cout << "\n";
    return 0;
}