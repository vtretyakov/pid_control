#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error_;
  double i_error_;
  double d_error_;
  double last_error_;
  double integral_limit_;

  /*
  * Coefficients
  */ 
  double Kp_;
  double Ki_;
  double Kd_;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double integral_limit);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  
  /*
   * Update the PID error variables given reference and current values.
   */
  void UpdateError(double ref_value, double current_value);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
