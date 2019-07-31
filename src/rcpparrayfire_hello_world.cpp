#include <RcppArrayFire.h>

// [[Rcpp::depends(RcppArrayFire)]]

using af::array;
using af::log;
using af::erfc;
using std::sqrt;
using std::exp;

af::array normcdf(array x) {
  return erfc(-x / sqrt(2.0)) / 2.0;
}

//' Test function
//' @export
// [[Rcpp::export]]
af::array put_option_pricer_af(RcppArrayFire::typed_array<f32> s, double k, double r,
                           double y, double t, double sigma) {
  
  array d1 = (log(s / k) + (r - y + sigma * sigma / 2.0) * t) / (sigma * sqrt(t));
  array d2 = d1 - sigma * sqrt(t);
  
  return normcdf(-d2) * k * exp(-r * t) - s * exp(-y * t) * normcdf(-d1); 
}