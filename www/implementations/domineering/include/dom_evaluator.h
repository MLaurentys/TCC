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
    float evaluate(const Domineering&);
    
    private:
    tuple<vector<move>, vector<move>> get_moves (const int_mat&, const semi_board&);
    tuple<int_mat, vector<semi_board>> break_configuration(const Domineering&);
    float evaluate_game_fixed(const Domineering&, semi_board);
    float eval_rec(const Domineering&);
};

#endif