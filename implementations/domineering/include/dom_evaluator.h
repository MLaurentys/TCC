#ifndef DOM_EVALUATOR_H
#define DOM_EVALUATOR_H

#include <vector>
#include <tuple>
#include <algorithm>

#include "domineering.h"
#include "definitions.h"

using std::tuple;
using std::vector;
using std::get;


class DomEvaluator{
    public:
    std::vector<game> evaluate(const Domineering&);
    void print_evaluation(game);

    private:
    tuple<vector<move>, vector<move>> get_moves (const int_mat&, const semi_board&);
    tuple<int_mat, vector<semi_board>> break_configuration(const Domineering&);
    float eval_rec(const Domineering&);


    game evaluate_game_fixed(int_mat&, semi_board);
};

#endif