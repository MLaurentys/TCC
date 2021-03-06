/*
 * This files contains the definition of the DomEvaluator class.
 */

#ifndef DOM_EVALUATOR_H
#define DOM_EVALUATOR_H

#include <vector>
#include <tuple>
#include <algorithm>
#include <memory>
#include <unordered_map>

#include "domineering.hpp"
#include "definitions.hpp"
#include "../../game_numbers/include/game_number_repr.hpp"


using std::tuple;
using std::vector;
using std::get;
using std::unordered_map;

/*
 * This class is used to evaluate the advantadges of given positions of the
 *  game called domineering.
 */
class DomEvaluator{
    public:
    std::vector<game> evaluate(const Domineering&);
    void print_evaluation(game&);
    static unordered_map<rectangle, game> hmap;

    private:
    static bool is_rect (const int_mat&, const semi_board&);

    tuple<vector<move>, vector<move>>
    get_moves (const int_mat&, const semi_board&);

    tuple<int_mat, vector<semi_board>>
    break_configuration(const Domineering&);
    
    float eval_rec(const Domineering&);

    game evaluate_game_fixed(int_mat&, semi_board&);
};

#endif