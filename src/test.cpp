#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

using arma::colvec;
using arma::log;
using arma::normcdf;
using std::sqrt;
using std::exp;

//' Test function
//' @export
// [[Rcpp::export]]
arma::colvec put_option_pricer_arma(arma::colvec s, double k, double r, double y, double t, double sigma) {

  colvec d1 = (log(s / k) + (r - y + sigma * sigma / 2.0) * t) / (sigma * sqrt(t));
  colvec d2 = d1 - sigma * sqrt(t);

  // Notice the use of % to represent element wise multiplication
  arma::colvec V = normcdf(-d2) * k * exp(-r * t) - s * exp(-y * t) % normcdf(-d1);

  return V;
}
