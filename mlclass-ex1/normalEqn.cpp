#include "normalEqn.h"

namespace mlclass{
namespace ex1{
    mat normalEqn(const mat& X, const mat& y){
        mat theta = pinv(X.t() * X) * (X.t() * y);
        return theta;
    }
}
} 
