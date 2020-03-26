#ifndef DOM_EVALUATOR_H
#define DOM_EVALUATOR_H

#include <vector>
#include <tuple>
#include <algorithm>

#include "domineering.h"
#include "definitions.h"

using std::tuple;
using std::vector;

class DomEvaluator{
    public:
    float evaluate(const Domineering&);
    
    private:
    vector<semi_board> break_configuration(const Domineering&); 
    float evaluate_game_fixed(const Domineering&, semi_board);
    float eval_rec(const Domineering&);
};

#endif