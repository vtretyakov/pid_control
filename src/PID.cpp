#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double integral_limit) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
  p_error_ = 0;
  i_error_ = 0;
  d_error_ = 0;
  last_error_ = 0;
  integral_limit_ = integral_limit;
}

void PID::UpdateError(double cte) {
  p_error_ = - cte;
  i_error_ += p_error_;
  d_error_ = p_error_ - last_error_;
  last_error_ = p_error_;
}

void PID::UpdateError(double ref_value, double current_value) {
  p_error_ = ref_value - current_value;
  i_error_ += p_error_;
  d_error_ = p_error_ - last_error_;
  last_error_ = p_error_;
}

double PID::TotalError() {
  double output = Kp_ * p_error_ + Ki_ * i_error_ + Kd_ * d_error_;
  if (output > 1.0) output = 1.0;
  else if (output < -1.0) output = -1.0;
  return output;
}

