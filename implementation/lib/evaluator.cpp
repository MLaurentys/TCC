//this file is temporary.
// will be removed when I finish the template implementation

#include "evaluator.hpp"
#include "../domineering/include/domineering.hpp"

evaluation evaluate(
        const Domineering& G,
        function<moves<move>(const int_mat&, const semi_board&)> get_moves,
        const int_mat& mat, const semi_board& sb) {
    auto moves = get_moves(mat, sb);
    //for (auto& move : )
}